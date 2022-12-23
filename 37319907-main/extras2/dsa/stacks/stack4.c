#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    int size;
    char *arr;
}stack;

int prec(char a)
{
    if(a == '#')
    {
        return 0;
    }
    else if(a=='+'||a=='-')
    {
        return 1;
    }
    else if(a=='*'||a=='/')
    {
        return 2;
    }
    else if(a=='^')
    {
        return 3;
    }
    return -1;
}

char pop(stack *s)
{
    char temp;
    temp = s->arr[s->top];
    s->top--;
    return temp;
}

void push(stack *s , char v)
{
    s->top++;
    s->arr[s->top] = v;
    return;
}

int main(void)
{
    char popped;
    stack *s = (stack *)malloc(sizeof(stack));
    s->top=-1;
    s->size = 100;
    s->arr = (char *)malloc(s->size * sizeof(char));
    s->top++;
    s->arr[s->top] = '#';
    char infix[100];
    printf("Input Infix : ");
    scanf("%s",infix);
    for(int i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='(')
        {
            push(s,infix[i]);
        }
        else if(infix[i]==')')
        {
            while(s->arr[s->top] != '(')
            {
                printf("%c",pop(s));
            }
            popped= pop(s);
        }
        else if(infix[i] == '+' ||infix[i] == '-' ||infix[i] == '*' ||infix[i] == '/' || infix[i] == '^')
        {
            while(prec(infix[i]) <= prec(s->arr[s->top]))
            {
                popped = pop(s);
                printf("%c",popped);
            }
            push(s,infix[i]);
        }
        else
        {
            printf("%c",infix[i]);
        }
    }
    while(s->arr[s->top] != '#')
    {
        printf("%c",pop(s));
    }
    printf("\n");

}