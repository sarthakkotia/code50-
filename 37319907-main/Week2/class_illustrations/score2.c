#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int n =get_int("How many scores?: ");
    int scores[n];
    int sum=0;
    float n2= n;

    for(int i=0;i<n;i++)
    {
        scores[i]=get_int("Score: ");
        sum=sum+scores[i];
    }

    printf("Average: %f\n",(sum)/n2);
}