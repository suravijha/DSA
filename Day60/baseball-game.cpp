// LeetCode 682
// You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
// You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:
// An integer x: Record a new score of x.
// '+': Record a new score that is the sum of the previous two scores.
// 'D': Record a new score that is the double of the previous score.
// 'C': Invalidate the previous score, removing it from the record.
// Return the sum of all the scores on the record after applying all the operations.

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> s;
        int res = 0;
        for (const string &op : operations)
        {
            if (op == "+")
            {
                int score = s.top();
                s.pop();
                int newTop = score + s.top();
                s.push(score);
                s.push(newTop);
                res += newTop;
            }
            else if (op == "D")
            {
                int score = s.top() * 2;
                s.push(score);
                res += score;
            }
            else if (op == "C")
            {
                res -= s.top();
                s.pop();
            }
            else
            {
                s.push(stoi(op));
                res += s.top();
            }
        }
        return res;
    }
};