#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3*sizeof(int));

    x[0] = 1;
    x[1] = 3;
    x[2] = 4;

    free(x);
}