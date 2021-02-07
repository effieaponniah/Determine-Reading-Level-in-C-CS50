// This program computes the approximate grade level needed to comprehend some text

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int get_index(string text);

int main(void)
{
    string text_input = get_string("Text: ");
    int index_value = get_index(text_input); 
    
    // Conditions to output the reading index
    if (index_value < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index_value >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index_value);
    }
}

// Reads text as a parameter and returns the index which determines approximate grade level
int get_index(string text)
{
    // Initializing all the values to zero
    int word_count = 0, sentence_count = 0, letter_count = 0;

    int index;

    // Counts the number of letters, words and sentences in the string of text
    for (int i = 0, textlength = strlen(text); i < textlength; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
        
        if ((i == 0 && text[i] != ' ') || (text[i] == ' ' && text[i + 1] != ' '))
        {
            word_count++;
        }
        
        if (text[i] == '.' ||  text[i]  == '?' || text[i]  == '!')
        {
            sentence_count++;
        }
    }

    // Calculating L and S values for the formula 
    float L = ((float)letter_count / word_count) * 100.0;
    float S = ((float)sentence_count / word_count) * 100.0;

    // Calculating grade level using Coleman-Liau index formula
    index = round(0.0588 * L - 0.296 * S - 15.8);

    return index; 
}