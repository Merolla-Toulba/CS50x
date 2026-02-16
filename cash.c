#include <cs50.h>
#include <stdio.h>

int calc_coins(int cen, int c);

int main(void)
{
    int change;
    int c;
    // Prompt the user for change owed, in cents
    do
    {
        change = get_int("Change Owed: ");
    }
    while (change < 0);

    // Calculate how many quarters you should give customer
    c = 25;
    int quar = calc_coins(change, c);
    change = change - (quar * c);

    // Calculate how many dimes you should give customer
    c = 10;
    int dim = calc_coins(change, c);
    change = change - (dim * c);

    // Calculate how many nickels you should give customer
    c = 5;
    int nick = calc_coins(change, c);
    change = change - (nick * c);

    // Calculate how many pennies you should give customer
    c = 1;
    int penn = calc_coins(change, c);
    change = change - (penn * c);

    // Get the sum of coins and print
    int total = quar + dim + nick + penn;
    printf("%i\n", total);
}

int calc_coins(int change, int c)
{
    int coin = 0;
    while (change >= c)
    {
        coin++;
        change = change - c;
    }
    return coin;
}
