// LeetCode 50
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }

        double res = 1.0;
        while (N > 0)
        {
            if (N & 1)
                res *= x;
            x *= x;
            N >>= 1;
        }
        return res;
    }
};