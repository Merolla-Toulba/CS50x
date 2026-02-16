#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            string text = get_string("plaintext:  ");
            encrypt(text, argv[1]);
            printf("ciphertext: ");
            return 0;
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

void encrypt(string plaintext, string key)
{
    int i = 0;
    int n = strlen(key);
    int m = strlen(plaintext);
    char listA[26] = {};
    char lista[26] = {};
    for (i = 0; i < n; i++)
    {
        if (isupper(key[i]) != 0)
        {
            listA[i] = key[i];
        }
        else
        {
            lista[i] = tolower(key[i]);
        }
    }
    for (i = 0; i < m; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            plaintext[i] = listA[i];
            printf("%c", plaintext[i]);
        }
        else if (islower(plaintext[i]) != 0)
        {
            plaintext[i] = lista[i];
            printf("%c", plaintext[i]);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
}
