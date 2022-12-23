#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text:  ");

    //count letters
    int letters = count_letters(text);

    //count words
    int words = count_words(text);

    //count sentences
    int sentences = count_sentences(text);

    //calculate index
    float l = ((float)letters / (float)words) * 100;
    float s = ((float)sentences / (float)words) * 100;
    int index = round(0.0588 * l - 0.296 * s - 15.8);
    // displaying index with the word grade and satisfying the question arguments
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


int count_letters(string text)
{
    int letter = 0;
    int length = strlen(text);
    // loop required
    for (int i = 0; i < length/*string length*/ ; i++)
    {
        // if character ascii is between the ascii values of A to Z or a to z it is a letter
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letter++;
        }
    }
    return letter;
}

int count_words(string text)
{
    int word = 1;
    // we start with 1 as the 1st word is not counted if we start from 0 as each space is one word as word is 1 number more than the number of spaces and  we are calculating spaces 
    int length = strlen(text);
    for (int i = 0; i < length/*string length*/ ; i++)
    {
        // if character ascii is ascii value of (space) it is a word or end of a word ie 1 word
        if (text[i] == ' ')
        {
            word++;
        }
    }
    return word;
}

int count_sentences(string text)
{
    int sentence = 0;
    int length = strlen(text);
    //loop required
    for (int i = 0; i < length; i++)
    {
        // if character ascii is ascii value of (space)/exclamation mark/quoestion mark it is a sentence/end of the sentence that is 1 sentence
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentence++;
        }
    }
    return sentence;
}