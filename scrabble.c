#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int compute_score(string n);
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // get user input
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // calculate scores
    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    // print winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string n)
{
    int score = 0;
    for (int i = 0, len = strlen(n); i < len; i++)
    {
        if (isupper(n[i]))
        {
            score += points[n[i] - 'A'];
        }
        else if (islower(n[i]))
        {
            score += points[n[i] - 'a'];
        }
    }
    return score;
}
