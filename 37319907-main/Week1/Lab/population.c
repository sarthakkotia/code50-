#include <stdio.h>
#include <cs50.h>

int main(void)
{

    // n is the population of present llamas entered by the user
    int n;
    do
    {
        n = get_int("Population of llamas present today: ");
        //To tell the user that is n<9 population will soon be stagnant
        if (n < 9)
        {
            printf("the population of llamas will quickly become stagnant!,Please reenter the value\n");
        }
    }
    while (n < 9);

    // p is original population to save the value of original n
    int p = n;
    // alive is population to be added ie alive after 1 year
    int alive;
    // dead is population to be deletd ie dead after 1 year
    int dead;
    
    // end is the population of llamas at the end
    int e;
    do
    {
        e = get_int("Population of llamas you want after certain time: ");
        //To tell the user that if e<n than we don't want them to be extict
        if (e < n)
        {
            printf("We want the population of llamas to grow!,Please reenter thevalue\n");
        }
    }
    while (e < n);

    //loop to detect number of years y=years
    int y = 0;
    //updating the population size
    while (n < e)
    {
        alive = n / 3;
        dead = n / 4;
        n = n + alive - dead;
        y++;
    }
    //print number of years
    printf("\nStart Size: %i\n", p);
    printf("End Size: %i\n", e);
    printf("Years: %i\n", y);
}
// note - dividing an integar in c automatically truncates the decimal parts
//incllude round  function from math.h