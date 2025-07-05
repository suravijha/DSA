// LeetCode 11
/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store. Notice that you may not slant the container.*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int ans = 0;
        int start = 0;
        int end = height.size() - 1;
        while (start < end)
        {
            ans = max(ans, (end - start) * min(height[start], height[end]));
            if (height[start] < height[end])
                start++;
            else
                end--;
        }
        return ans;
    }
};