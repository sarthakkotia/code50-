#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    /*
    string s = get_string("s:");

    string t=s;

    t[0] = toupper(t[0]);

    printf("s:%s\n",s);
    printf("t:%s\n",t);
    */


   char *s = get_string("s:");
   char*t = malloc(strlen(s)+1);

    if(t==NULL)
    {
        return 1;
    }

    strcpy(t,s);

   /*for(int i=0;i<(strlen(s)+1);i++)
   {
       t[i] = s[i];
   }
   */
  if(strlen(t)>0)
  {
      t[0] = toupper(t[0]);
  }

   printf("t:%s\n",t);
   printf("s:%s\n",s);

   free(t);
   return 0;
}
