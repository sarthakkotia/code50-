#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

bool only_alpha(string s);
bool unique(string s);
char ciphered(char c, string s);

int main(int argc, string argv[])
{
    // the user should always execute only with 2 argc ie the execution and the key
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    // The key entered should be of exact length of 26 letters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // to check that each character of the key is an alphabet
    bool alpha = only_alpha(argv[1]);
    if (alpha == false)
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    // every character of the key must be unique
    bool u = unique(argv[1]);
    if (u == false)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    // ask the user for the text to be ciphered as plaintext
    string plaintext = get_string("plaintext: ");
    // the array ciphertext equal to the length of the plaintext
    char ciphertext[strlen(plaintext)];
    // a loop so that each value of the cipheretext array to be ciphered and computed and saved to it
    for (int i = 0; i < strlen(plaintext); i++)
    {
        ciphertext[i] = ciphered(plaintext[i], argv[1]);
    }
    printf("ciphertext: ");
    // a loop to print each value of the ciphertext array without any new line
    for (int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", ciphertext[i]);
    }
    //now print a new line after print of all letters
    printf("\n");

}

bool only_alpha(string s)
{
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            return false;
        }
    }
    return true;
}


bool unique(string s)
{
    //an array alpha of the exact length of the entered key ie s / argv[1] 
    char alpha[strlen(s)];
    // convert each character of the alpha to the capital version of the entered key so that there is no discretion while checking between the individual keys
    for (int i = 0; i < strlen(s); i++)
    {
        // to upper so that there is no discretion between the capital/small letters
        alpha[i] = toupper(s[i]);
    }
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        for (int j = length; j > i; j--)
        {
            // to check that the jth value of the key is not equual to the ith value
            // i from left to right ie beginning to end and j from right to left from end to beginning 
            if (alpha[j] == alpha[i])
            {
                return false;
            }
        }
    }
    return true;
}

char ciphered(char c, string s)
{
    // if the character is not a alphabetical letter then return as it was
    if (isalpha(c) == 0)
    {
        return c;
    }
    // an array of alphabet to maintain / save the index value which will be used to get that index key value
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // an array key of length of 26 ie the number of letters
    char key[26];
    // making so that every vvalue of argv[1] can be saved to key so that cmpution/relation could be easy onwards
    for (int i = 0; i < strlen(s); i++)
    {
        key[i] = s[i];
    }
    // the upper variable is going to be used later to return
    int upper = isupper(c);
    // a variable character which first convert the given input to lowercase to do the computation
    char character = tolower(c);
    int index = 0;
    for (int i = 0; i < 26; i++)
    {
        // if the alphabet[i] the value is same as character then the index is i
        if (character == alphabet[i])
        {
            index = i;
        }
    }
    // cipher is the letter/character to be returned
    char cipher;
    // if upper==0 ie the letter was lowercase
    if (upper == 0)
    {
        cipher = tolower(key[index]);
    }
    else
        // ie the letter was uppercase
    {
        cipher = toupper(key[index]);
    }
    return cipher;
}