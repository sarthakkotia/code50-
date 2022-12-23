#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Write an Integar: ");
    // if number when diided by 2 gives remander 0 is even
    if (n % 2 ==0)
    {
        printf("%i is even \n",n);
    }
    // if number when diided by 2 gives remander 1 is odd
    else
    {
        printf("%i is odd \n",n);
    }
}