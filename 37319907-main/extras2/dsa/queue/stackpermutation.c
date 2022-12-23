#include <stdio.h>
#include <stdlib.h>

int q1[100];
int frontq1 = -1;
int rearq1 = -1;

int q2[100];
int frontq2 = -1;
int rearq2 = -1;

int stack[100];
int tops = -1;

void pushq1(int val)
{
    if (frontq1 == rearq1)
    {
        frontq1++;
        rearq1++;
    }
    else
    {
        rearq1++;
    }
    q1[rearq1] = val;
}

void pushq2(int val)
{
    if (frontq2 == rearq2)
    {
        frontq2++;
        rearq2++;
    }
    else
    {
        rearq2++;
    }
    q2[rearq2] = val;
}

int isnotemptyq1()
{
    if (frontq1 == rearq1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int popq1()
{
    int temp;
    temp = q1[frontq1];
    frontq1--;
    return temp;
}
int stackisnotempty()
{
    if (tops == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void popq2()
{
    frontq2++;
}
void popstack()
{
    tops--;
}
int q1isempty()
{
    if(frontq2==rearq2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(void)
{
    int fa[] = {1, 2, 3};
    int sa[] = {2, 1, 3};
    for (int i = 0; i < 3; i++)
    {
        // PUSH INPUT TO Q1
        pushq1(fa[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        // PUSH SA TO Q2;
        pushq2(sa[i]);
    }
    while (&isnotemptyq1)
    {
        int ele;
        ele = (int)popq1;
        if (ele == q1[frontq1])
        {
            while (&stackisnotempty)
            {
                if (stack[tops] == q2[frontq2])
                {
                    popstack;
                    popq2;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            tops++;
            stack[tops] = val;
        }
    }
    if(q1isempty==1 && stackisnotempty==0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}