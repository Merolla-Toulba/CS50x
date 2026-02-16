#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get card number from user
    string card_no = get_string("Number: ");

    // calculate checksum for the card
    // idk fa hasebha keda b2a weselna le haga el ba2y b3den :(

    // If yes, from which company
    int n = strlen(card_no);
    if ((n == 13 || n == 16) && card_no[0] == '4')
    {
        printf("VISA\n");
    }
    else if (n == 16 && card_no[0] == '5')
    {
        printf("MASTERCARD\n");
    }
    else if (n == 15 && card_no[0] == '3')
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
