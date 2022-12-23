#include <stdio.h>
#include <string.h>

void sort(char arr[], int length)
{
    char temp;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main(void)
{
    char newyear[100];
    char christmasmen[100];

    scanf("%s", newyear);
    scanf("%s", christmasmen);

    char concat[200];
    strcpy(concat, strcat(newyear, christmasmen));
    sort(concat, strlen(concat));
    char input[100];
    scanf("%s", input);
    sort(input, strlen(input));
    for (int i = 0; i < strlen(concat); i++)
    {
        if (input[i] != concat[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}