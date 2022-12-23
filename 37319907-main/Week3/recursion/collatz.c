#include<stdio.h>
#include<cs50.h>

int collatz(int n);
int steps = 0;

int main(void)
{
    int a = get_int("Number?: ");
    printf("%i\n",collatz(a));
}


int collatz(int n)
{
    //base case
    if(n==1)
    {
        return steps;
    }

    //recursive cases
    else
    {
        if(n%2 == 0)
        {
            steps++;
            return collatz(n/2);
        }
        else
        {
            steps++;
            return collatz(3*n+1);

        }
    }

}