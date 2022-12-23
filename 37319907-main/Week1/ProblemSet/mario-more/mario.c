#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int rows;
    // ask for a input b/w 1to 8 if not then reprompted
    do
    {
        rows = get_int("Height: ");
    }
    while (rows <= 0 || rows > 8);

    int x = 0;
    while (x < rows)
    {
        x++;
        // to print space first number of spaces keep decreasing as rows increasing
        for (int space = rows; space > x; space--)
        {
            printf(" ");
        }
        // to print hashes
        for (int hash = 0; hash < x; hash++)
        {
            printf("#");
        }
        // to pprint the constant space space which is required by the question
        printf("  ");
        // to print the hashes without spaces ie the  original way to print hashes
        for (int hash = 0; hash < x; hash++)
        {
            printf("#");
        }
        // to go to nest line after 1 row is done
        printf("\n");
    }
}
