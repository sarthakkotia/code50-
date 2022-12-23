#include <stdio.h>
#include <cs50.h>

int main (void)
{
    const int MINE = 50 ;
    int points = get_int("How many points did you lose last time: ");
    
    if (points>MINE)
    {
        printf("%i is more than mine :) \n",points);
    }
    else if (points<MINE)
    {
        printf("%i is less than mine :( \n",points);
    }
    else
    {
        printf("%i is equal to mine \n",points);
    }
}