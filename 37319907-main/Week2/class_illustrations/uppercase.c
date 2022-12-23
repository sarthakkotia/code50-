#include<stdio.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    string s =get_string("Before: ");
    printf("After:  ");

    //loop required ti iterate
    for(int i=0,n=strlen(s);i<n;i++)
    {
        // if condition is it lowercase
        if(s[i]>='a' && s[i]<='z')
        {
            // if yes then converted to uppercase
            printf("%c",s[i]-32);
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("\n");
}
