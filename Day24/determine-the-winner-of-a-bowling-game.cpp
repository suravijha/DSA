// LeetCode 2660
/* You are given two 0-indexed integer arrays player1 and player2, representing the number of pins that player 1 and player 2 hit in a bowling game, respectively.
The bowling game consists of n turns, and the number of pins in each turn is exactly 10.
Assume a player hits xi pins in the ith turn. The value of the ith turn for the player is:
2xi if the player hits 10 pins in either (i - 1)th or (i - 2)th turn.
Otherwise, it is xi.
The score of the player is the sum of the values of their n turns.
Return
1 if the score of player 1 is more than the score of player 2,
2 if the score of player 2 is more than the score of player 1, and
0 in case of a draw.*/

class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int pl1score = 0;
        int pl2score = 0;
        int n = player1.size();

        for (int i = 0; i < n; i++)
        {
            // For player1
            if ((i >= 1 && player1[i - 1] == 10) || (i >= 2 && player1[i - 2] == 10))
                pl1score += 2 * player1[i];
            else
                pl1score += player1[i];

            // For player2
            if ((i >= 1 && player2[i - 1] == 10) || (i >= 2 && player2[i - 2] == 10))
                pl2score += 2 * player2[i];
            else
                pl2score += player2[i];
        }

        if (pl1score > pl2score)
            return 1;
        else if (pl2score > pl1score)
            return 2;
        return 0;
    }
};