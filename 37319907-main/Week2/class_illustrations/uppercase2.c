#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
    string s =get_string("Before: ");
    printf("After:  ");

    //loop required ti iterate
    for(int i=0,n=strlen(s);i<n;i++)
    {
        if(islower(s[i]) !=0)
        {
            printf("%c",s[i]-32);
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
}
