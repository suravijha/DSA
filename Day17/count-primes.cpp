// LeetCode 204
// Given an integer n, return the number of prime numbers that are strictly less than n.

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<int> prime(n + 1, 1);
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                count++;
                for (int j = 2 * i; j < n; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        return count;
    }
};