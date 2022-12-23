#include<stdio.h>
#include<cs50.h>

int main(void)
{
    // To ask the user for givingthe input ie a credit card number
    long n = get_long("Number: ");

    // declaring a n2=n which will be used later to calculate first and second digit
    long n2 = n;
    
    // the digit variable is usedto identify/keep the individual digits of the entered number and perform operarions as required
    int digit;
    // the count variable is used to determine the position of  the digit used with respect to the last digit
    int count = 0;
    // the sum2 is the summ of (every other digit x2 starting with second to last digit)
    int sum2 = 0;
    // sum1 is the sum of the remaining digits
    int sum1 = 0;

    // loop required to save the digit and do the checksum 
    do
    {
        digit = n % 10;
        n = n / 10;
        count++;
        if (count % 2 == 0)
        {
            // to multiply every second to last digit by two and add it to a sum2
            digit = digit * 2;
            if (digit >= 10)
            {
                // to check that if any number 2x is 2 digit then add its digits individually
                digit = (digit % 10) + 1;
            }
            sum2 = sum2 + digit;
        }
        else
        {
            sum1 = sum1 + digit;
        }
    }
    while (n != 0);

    //to calculate first and second digit
    int first_digit;
    int second_digit;
    // i is a integar used to calculate the second digit in the loop
    int i = 0;
    // n3 is the inputted number
    long n3 = n2;
    do
    {
        first_digit = n2 % 10;
        n2 = n2 / 10;
        i++;
        if (i >= 2)
        {
            second_digit = n3 % 10;
            n3 = n3 / 10;
        }
    }
    while (n2 != 0);
    
    // the final result to checksum and the count and if the result we need is wrong make it INVALID
    int checksum = sum1 + sum2;
    if (checksum % 10 == 0)
    {
        if (count == 15)
        {
            if (first_digit == 3 && (second_digit == 4 || second_digit == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 16)
        {
            if (first_digit == 5 && (second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4 || second_digit == 5))
            {
                printf("MASTERCARD\n");
            }
            else if (first_digit == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 13)
        {
            if (first_digit == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}