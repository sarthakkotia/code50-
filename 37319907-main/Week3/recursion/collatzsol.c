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
    if(n==1)
        return 0;
    else if((n%2)==0)
        return 1+collatz(n/2);
    else
        return 1+collatz(3*n+1);
}