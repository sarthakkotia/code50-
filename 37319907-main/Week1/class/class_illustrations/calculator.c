#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float x = get_float("First Number: ");
    float y = get_float("Second Number: ");
    // perform addition
    float z = x/y ;
    printf("Divison of The two numbers are :%0.50f \n",z);
}