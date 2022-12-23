#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open memory card
    //  where the function fopen returns an pointer to the file representing the opened file
    FILE *file = fopen(argv[1], "r");
    // r stand for read mode

    if (file == NULL)
    {
        return 1;
    }

    // look for a jpeg
    // every jpeg begins with a distict header ie the first byte for every jpeg file is 0xff first three bytes re 0xff 0xd8 0xff and the last byte is 0xe0...0xef
    BYTE buffer[512];
    // fread function
    // this function is used to read files
    // fread(data,size,number,inptr)
    // data - pointer to where to store data where you are reading likely some buffer of some kind that might be an array
    // size - size of each element to read
    // number - number of elements to read
    // inptr which is the file that we are going to read the data from

    int name = -1;
    // here the name is -1 as we will increase and name all the images according to it later
    char output[8];
    // here size is 8 it includes 3 digits of integars the dot and the three char called jpg's and lastly \0
    FILE *image;
    // it's the new file that we are writing to
    while (fread(buffer, 1, 512, file) == 512)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // here we have used a trick known as bitwise arithmetic what is says in first brackets is
            // just go into the first 4 bits of this 8 bit byte and set the reamianing 4 bits to zero so 0xe0,0xe1...all become 0xe0 as we have cleared the last 4 bits
            // now we have found the beginnig of the jpeg file
            if (name != -1)
            {
                fclose(image);
            }
            name++;
            // we wil create a new file where we will write this data to
            // well each file file should have a very particular file name as digit digit digit.jpeg ie 000.jpeg so we have to keep track on many jpeg's we have found so far so that we can name them accordingly
            // tocreate a string of format digit digit digit.jpeg
            // we use sprintf function
            // it takes the name of the string to format to ie the file name
            // secind one is the format string %03i means to print an integar with three digits to represent it
            // the number you want to substitute
            // make sure that file name has enough memory to fully represent this entire name

            sprintf(output, "%03i.jpg", name);
            image = fopen(output, "w");
            // now we have used w ie for write
            fwrite(buffer, 1, 512, image);
            // to write to a file we can use the inverse of fread ie fwrite
            // fwrite(data,size,nmber,outputptr)
            // data - pointer to bytes that will be written to a file
            // size - size of each element to write
            // number - number of elements to write
            // outptr - file pointer that you want to write the data to
        }
        else if (name > -1)
        {
            // ie it's not a starting of a new JPEG it's the continution to the previous one saved onto the next block of memory card
            fwrite(buffer, 1, 512, image);
        }
    }
    fclose(image);
    fclose(file);
}