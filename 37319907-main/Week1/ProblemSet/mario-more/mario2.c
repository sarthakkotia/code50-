#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int rows;
    do
    {
        rows = get_int("Height: ");
    }
    while(rows<=0 || rows > 8);

    int space;
    for(int i = 1; i<=rows;i++)
    {
        space = rows-i;
        for(int j=0;j<space;j++)
        {
            printf(" ");
        }
        for(int k=0 ; k<i;k++)
        {
            printf("#");
        }
        printf("  ");
        for(int l=0;l<i;l++)
        {
            printf("#");
        }
        printf("\n");
    }
}