#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1==score2)
    {
        printf("Tie!\n");
    }
    else if(score1>score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score2>score1)
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // to find the number of letters in the word written
    // ek aur array bannegi of alphabetss small ki ek aur capital ke ek
    // fir word ke character ko is array ke ussi character ki position yaad karke us position wala point nikalna padega from points array aur add karna padega in score
    //ek chiz aur check karna ki char small aur capital to check kar sakta hain kya?

    // array to check the position of written alphabet in word
    char alphabet[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int arrlength=0;
    while(alphabet[arrlength] != '\0')
    {
        printf("%i\n",alphabet[arrlength]);
        printf("%c\n",alphabet[arrlength]);
        arrlength++;
    }
    printf("Length=%i\n",arrlength);
    
    int score=0;
    int position =0;
    // strlen is used to find the length of the written word
    int length =strlen(word);

    // loop required
    for(int i=0;i<length;i++)
    {
        // tolower function used such that eevry charcater written is converted to lwercase so that it can be compared with the alphabet array we made
        char c = word[i];
        for(int z=0;z<26;z++)
        {
            if(c==isupper(alphabet[z])|| c==islower(alphabet[z]))
            {
                position=z;
                score=score+POINTS[position];
                z=26;
            }
        }
    }
    return(score);
}
