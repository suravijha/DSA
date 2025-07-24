// LeetCode 36
/* Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.*/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<char>> rows, cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                int ch = board[r][c];
                if (ch == '.')
                    continue;

                pair<int, int> key = {r / 3, c / 3};

                if (rows[r].count(ch) || cols[c].count(ch) || squares[key].count(ch))
                    return false;

                rows[r].insert(ch);
                cols[c].insert(ch);
                squares[key].insert(ch);
            }
        }

        return true;
    }
};