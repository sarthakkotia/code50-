#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int rows;
    // ask a number b/w 1 to 8 repeated until the input is valid
    do
    {
        rows = get_int("Please write a number between 1 and 8: ");
    }
    while (rows <= 0 || rows > 8);


// The main loop
    int x = 0;
    // the parent while loop is used to switch to next line when the output needed is submitted
    while (x < rows)
    {
        //if x is less than the rows entered add 1 to x
        x++;
        // we need the spaces loop and the # loop to run simultaneouly or back to back so as space comes first therefore spaces loop first
        // loop for printing the spaces
        for (int space = rows; space > x; space--)
        {
            // space = rows inputed then until space>rows loop will run then after the tthe completion of loop decrease value of space by 1
            // space will print like rows=3 spaces= 2 \n spaces=1 \n loop terminated
            printf(" ");
        }
        // loop for printing the #
        for (int hash = 0; hash < x; hash++)
        {
            // to print # in a increasing manner ie 1,2,3...  until the number of hashes printed becomes equal to x 
            printf("#");
        }
        printf("\n");
    }
}