#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    char s[100];
    char final[13];
    int length;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        if(strlen(s)>10)
        {
            length = strlen(s)-2;
            final[0] = s[0];
            final[1] = (char)(length /10)+48;
            final[2] = (char)(length % 10)+48;
            final[3]=s[strlen(s)-1];
        }
        else
        {
            strcpy(final,s);
        }
    }

    printf("%s\n",final);
}