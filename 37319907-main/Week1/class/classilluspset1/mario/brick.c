#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // To check that the gien input of size is always >0 ie not negative integars
    int n;
    do
    {
        n=get_int("size of square?: ");
    }
    while(n<0);
    // for each row
    for (int j = 0; j < n; j++)
    // parent loop help to tell us the number of rows by running the inner loop and switch to next lline with help of \n and this happens the number of times we need the rows to be we can say that it helps to print vertically 
    {
        //for each column
        for(int i = 0; i < n; i++)
        {
            printf("#");
        }
        // go to next line
        printf("\n");
    }
}