#include <stdio.h>
#include <string.h>
#include <ctype.h>

int stack[100];
int top=-1;

int isoperand(char val)
{
    if(isdigit(val)!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int val)
{
    top++;
    stack[top] = val;
}

int pop()
{
    int temp;
    temp = stack[top];
    top--;
    return temp;
}

int main(void)
{
    char exp[] = "231*+9-";
    int op1;
    int op2;
    int op3;
    for(int i=0;i<strlen(exp);i++)
    {
        if(isoperand(exp[i])==1)
        {
            push((int)exp[i]-(int)'0');
        }
        else
        {
            op1 = pop();
            op2 = pop();
            switch(exp[i])
            {
                case '+':
                    op3=op1+op2;
                    break;
                case '-':
                    op3 = op2-op1;
                    break;
                case '*':
                    op3 = op1*op2;
                    break;
                case '/':
                    op3= op2/op1;
                    break;
            }
            push(op3);
        }
    }
    printf("%d",pop());
}