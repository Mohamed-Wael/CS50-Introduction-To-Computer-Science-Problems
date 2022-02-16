#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int letter_count(string text);
int word_count(string text);
int sentence_count(string text);

int main (void)
{
    string text = get_string("Text:");
    int letters = letter_count(text);
    int words = word_count(text);
    int sentences = sentence_count(text);
    float l = ((float) letters/words)*100.0;
    float s = ((float) sentences/words)*100.0;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n",grade);
    }

    
}

int letter_count(string text)
{
    int n = strlen(text);
    int i;
    int count = 0;
    
    for (i = 0; i < n; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            count++;
        }
    }
    return count;
}

int word_count(string text)
{
    int n = strlen(text);
    int i;
    int count = 1;
    
    for (i = 0; i < n; i++)
    {
        if (text[i] == ' ')
        {
            count ++;
        }
    }
    return count;
    
}

int sentence_count(string text)
{
    int n = strlen(text);
    int i;
    int count = 0;
    
    for (i = 0; i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count ++;
        }
    }
    return count;
}