#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

bool only_digits(string s);

char rotate(char c, int i);

int main(int argc, string argv[])
{
    // To check that the number of arguments written by the user must always be 2 ie the executing command and the key 
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // only_digits is a custom function which checks that in the string inputted each and every corresponding charcter of that string is a digit ie 0-9 and return a boolean value
    bool digit = only_digits(argv[1]);
    // if the string contains not a digit
    if (digit == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // argv[1] is the key written by the user while execution which is in the form of a string the atoi f(x) convert string into an integar this is savevd onto the variable key 
    int key = atoi(argv[1]);
    // ask the user for the text to be ciphered as plaintext
    string plaintext = get_string("plaintext: ");
    // ciphertext is an array of char values which have a definitive length ie the length of the plaintext entered by the user here we cannot declare the ciphertext as the built in string as it requires the value instantaneously or we havev to write NULL which caused some non favourable output after the execution 
    char ciphertext[strlen(plaintext)];
    // a loop to fill in the individual value of ciphertext to the required ciphered char as per by the formula/f(x)
    for (int i = 0; i < strlen(plaintext); i++)
    {
        ciphertext[i] = rotate(plaintext[i], key);
    }
    printf("ciphertext:");
    // a loop to print the individual characters of the ciphertext as an array connot be prrinted as a whole
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");

}


bool only_digits(string s)
{
    // to check the the characters are digits from 0-9
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        // is digit f(x) return a 0 when the character is not a number b/w 0-9
        if ((isdigit(s[i])) == 0)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int i)
{
    //to check that the charcter is alphabet
    // isalpha f(x) return 0 is the character is not a alphabet
    if ((isalpha(c)) == 0)
    {
        // if the character is not an alphabet then return the character as it is
        return c;
    }
    // variables reqd for the formula/f(x)
    int character = 0;
    int alphaindex = 0;
    // alphaindex so that the index of the alphabet is defines as we need A=0,B=1....
    int formula = 0;
    // to see that the charcter is in lowercase
    int lower = islower(c);
    // convert the alphabet to uppercase
    char upper = toupper(c);
    // it makes the alphaindex ie if character is A now ts index is 0.....
    alphaindex = (int)upper - (int)'A';
    formula = (alphaindex + i) % 26;
    character = formula + (int)'A';
    char ch = (char)character;
    
    // if it is lowercase then it is a non zero integar
    if (lower != 0)
    {
        // convert character to lowercase
        ch = tolower((char)character);
    }
    return ch;
}