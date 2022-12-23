// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
// read the header form the input file and write it ot he output
//we need to create some place in the computer's memory into which to read that header

    uint8_t header[HEADER_SIZE];
    // declaration of an array called header it's type is a type for unsigned 8 bit integars and we want HEADER_SIZE bytes
    // read that buffer from the input file
    fread(header, HEADER_SIZE, 1, input);
    //writying the content of that header to the output file
    fwrite(header, HEADER_SIZE, 1, output);

    // this made the the first44bytes to be copied to output
    // TODO: Read samples from input file and write updated data to output file
    //for each that two byte sample we have to read that sample in the memory modify it to adjust it's volume  and write it to the updated file
    int16_t buffer;
    //here we have declared another buffer but now that buffer is not needed to store 44bytes of data we just need it to store 2 bytes of data and therefore it's datatype
    // we will do a loop we will use the fread funtion to read from the input file into the buffer passing in the address of the buffer and we will read one sample of 16bits or 2 bytes each
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        //write the data from the buffer to output
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
//fread return to us the number of block of data it would read so once it no longer is able to read any more data fread would return 0 theefore breaking the loop
    // Close files
    fclose(input);
    fclose(output);
}
