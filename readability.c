#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letter_count(string s);
int word_count(string s);
int sentence_count(string s);

int main(void)
{
    // promt the user for text
    string tex = get_string("Text: ");
    // create a function to get the grade level
    int let = letter_count(tex);
    int wor = word_count(tex);
    int sen = sentence_count(tex);

    float gl = (0.0588 * ((float) let / (float) wor) * 100) -
               (0.296 * ((float) sen / (float) wor) * 100) - 15.8;
    gl = round(gl);
    int gradelevel = gl;
    // print the grade level
    if (gl < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gl >= 1 && gl < 16)
    {
        printf("Grade %i\n", gradelevel);
    }
    else if (gl >= 16)
    {
        printf("Grade 16+\n");
    }
}

int letter_count(string s)
{
    int l = 0;
    int i;
    int n = 0;

    for (i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]) != 0)
        {
            l++;
        }
    }
    return l;
}

int word_count(string s)
{
    int w = 0;
    int i;
    int n = 0;

    for (i = 0, n = strlen(s); i < n; i++)
    {
        if (isspace(s[i]) != 0)
        {
            w++;
        }
    }
    int wor = w + 1;
    return wor;
}

int sentence_count(string s)
{
    int sen = 0;
    int i;
    int n = 0;

    for (i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '?' || s[i] == '.' || s[i] == '!')
        {
            sen++;
        }
    }
    return sen;
}
