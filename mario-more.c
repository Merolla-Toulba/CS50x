#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // get user input
    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8);

    // print pyramid
    for (int col = 0; col < n; col++)
    {
        // printing pyramid 1
        for (int space = 1; space < n - col; space++)
        {
            printf(" ");
        }
        for (int hash = 0; hash < col + 1; hash++)
        {
            printf("#");
        }

        // space inbetween
        printf("  ");

        // print 2nd pyramid
        for (int hash2 = 0; hash2 < col + 1 ; hash2++)
        {
            printf("#");
        }
        // new line
        printf("\n");
    }
}
