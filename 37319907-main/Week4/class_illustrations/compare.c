#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("S:");
    string t = get_string("T:");

    if(strcmp(s,t)==0)
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}