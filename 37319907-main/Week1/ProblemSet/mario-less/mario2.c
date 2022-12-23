#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height<1 || height>8);

    int space;

    for(int i = 1; i<=height;i++)
    {
        space = height - i;
        for(int j = 0; j < space; j++)
        {
            printf(" ");
        }
        for(int k = 0; k < i ; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}