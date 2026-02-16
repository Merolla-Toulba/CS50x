#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // prompting the user for a no. between 1 and 8 using do-while loop
    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8);

    // printing the actual pyramid
    for (int col = 0; col < n; col++)
    {
        // loop starts at 1 to end a row early so that there is no space before last row
        for (int space = 1; space < n - col; space++)
        {
            printf(" ");
        }

        for (int hash = 0; hash < col + 1; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}
