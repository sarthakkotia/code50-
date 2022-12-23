#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float amount = get_float("Amount in rupees: ");
    int paise = round(amount*100);
    printf("paise= %i\n",paise);
}