#include <cs50.h>
#include <stdio.h>

// this get cents function do not want any specific input however it does give a integar output or return an integar
int get_cents();//this is a protoype that means it tells that when this function is used go to the required place it also verifies that this function does exist
// this function wants a parameter ie the integar cents and return a integar
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();
    // cents=c 

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    // new cents after deduction of quarters
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    // new cents after deduction of dimes
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    // new cents after deduction of dimes
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    // new cents after deduction of dimes
    cents = cents - pennies * 1;


    // Sum coins
    int coins = quarters + dimes + nickels + pennies;
    printf("\n");

    // Print total number of coins to give the customer
    printf("Total number of coins to be given: %i\n", coins);
}


//Implement get_cents in such a way that the function prompts the user for a number of cents using get_int and then returns that number as an int. If the user inputs a negative int, your code should prompt the user again. 
int get_cents(void)
{
    int c;
    do
    {
        c = get_int("Number of cents owed: ");
        
    }
    while (c < 0);
    return c;
}


int calculate_quarters(int cents)
{
    int q;
    q = cents / 25;
    return q;
}

int calculate_dimes(int cents)
{
    int d;
    // new cents after deduction
    d = cents / 10;
    return d;
}

int calculate_nickels(int cents)
{
    int n;
    // new cents after deduction
    n = cents / 5;
    return n;
}

int calculate_pennies(int cents)
{
    int p;
    // new cents after deduction
    p = cents;
    return p;
}
