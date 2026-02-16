#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_digits(string s);
void cipher_convert(string plain, int cipher);

int main(int argc, string argv[])
{
    // checks if the cipher is included in command
    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // checks if there is too many commands
    else if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // checks if there are 2 commands 1 a chiper
    else if (argc == 2)
    {
        // if 2 are included checks if the cipher is a number
        if (only_digits(argv[1]) == 0)
        {
            /* changes cipher to int, gets plaintext from user, and calls a fn to change the text
            based on cipher */
            int cipher = atoi(argv[1]);
            string plain = get_string("plaintext:  ");
            printf("ciphertext: ");
            cipher_convert(plain, cipher);
            return 0;
        }
        // if not returns error
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
}

// makes sure that the cipher is numeric
int only_digits(string s)
{
    int i = 0;
    int n = strlen(s);
    for (i = 0; i < n; i++)
    {
        if (isdigit(s[i]) != 0)
        {
            continue;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

// convers plaintext to chiper text
void cipher_convert(string plain, int cipher)
{
    int i = 0;
    int n = strlen(plain);
    for (i = 0; i < n; i++)
    {
        // checks whether i is a letter & if yes converts it
        if (isalpha(plain[i]) != 0)
        {
            // if lowercase
            if (plain[i] >= 'a' && plain[i] <= 'z')
            {
                int p = plain[i] - 'a';
                int k = cipher;
                char final = (p + k) % 26;
                printf("%c", (char) final + 'a');
            }
            // if uppercase
            else if (plain[i] >= 'A' && plain[i] <= 'Z')
            {
                int p = plain[i] - 'A';
                int k = cipher;
                char final = (p + k) % 26;
                printf("%c", (char) final + 'A');
            }
        }
        // if not a letter prints the same
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
