#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask what is your name
    string name = get_string("What is your name? ");
    // Hello to the aforementioned name
    printf("Hello, %s\n", name);
}