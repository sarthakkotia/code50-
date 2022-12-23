#include<stdio.h>
#include<cs50.h>

bool valid_triangle(int a ,int b ,int c);
int main(void)
{
    int x = get_int("A triangle side: ");
    int y = get_int("A triangle side: ");
    int z = get_int("A triangle side: ");
    bool answer = valid_triangle(x,y,z);
    if(answer==false)
    {
        printf("not a valid trianagle\n");
    }
    else
    {
        printf("a valid trianagle\n");
    }
}

bool valid_triangle(int a , int b ,int c)
{
    if(a<=0||b<=0||c<=0)
    {
        return false;
    }
    else
    {
        if(a + b >= c || a + c >= b || b + c >= a)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}