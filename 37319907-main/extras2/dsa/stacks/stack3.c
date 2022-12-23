#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    int size;
    int *arr;
} stack;

void push(stack *s, char val)
{
    s->top++;
    s->arr[s->top] = val;
    return;
}

char pop(stack *s)
{
    char temp;
    temp = s->arr[s->top];
    s->top--;
    return temp;
}

int match(char a, char b)
{
    if (a == ')' && b == '(')
    {
        return 1;
    }
    else if (a == '}' && b == '{')
    {
        return 1;
    }
    else if (a == ']' && b == '[')
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    char val;
    stack *s;
    s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc(s->size * sizeof(int));
    char input[100];
    printf("Input the characted input expression : ");
    scanf("%s", input);
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{')
        {
            push(s, input[i]);
        }
        else if (input[i] == ')' || input[i] == ']' || input[i] == '}')
        {
            val = pop(s);
            if (match(input[i], val) == 0)
            {
                printf("Parenthesis does not match\n");
                return -1;
            }
        }
    }
    printf("Parenthesis matched\n");
}