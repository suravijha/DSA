// LeetCode 42
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.empty())
            return 0;

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int res = 0;
        while (l < r)
        {
            if (leftMax < rightMax)
            {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            }
            else
            {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};