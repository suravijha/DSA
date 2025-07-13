/* A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. 
A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. 
You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.*/

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();

        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() > 1)
        {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (mat[a][b])
                s.push(b);
            else
                s.push(a);
        }

        int candidate = s.top();

        for (int i = 0; i < n; i++)
        {
            if (i == candidate)
                continue;
            if (mat[candidate][i] == 1)
                return -1;
        }

        for (int i = 0; i < n; i++)
        {
            if (mat[i][candidate] == 0)
                return -1;
        }

        return candidate;
    }
};