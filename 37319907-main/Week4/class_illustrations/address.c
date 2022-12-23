#include <stdio.h>

int main(void)
{
    /*
    int n = 50;
    int *p = &n;
    printf("%p\n",&n);
    printf("%p\n",p);
    printf("%i\n",*p);
    */
   /*
   string s = "hi!";
   printf("%s\n",s);
   char *w = "hi!";
   printf("%s\n",w);
    */
   /*
   string s = "HI!";
   char c = s[0];
   char *p = &c;
   printf("%p\n",p);
   printf("%p\n",s);
   */
  /*
  char *s = "HI!";
  char *p = &s[0];
  char *p1 = s;
  printf("%p\n",p);
  printf("%p\n",s);
  printf("%p\n",p1);
  */


  char *s = "HI!";
  printf("%c\n",*s);
  printf("%c\n",*(s+1));
  printf("%c\n",*(s+2));
  printf("%c\n",*(s+3));
}