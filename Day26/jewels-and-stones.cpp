// LeetCode 771
// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<int, int> hash;
        for (char c : stones)
        {
            hash[c - 'a']++;
        }
        int ans = 0;
        for (char c : jewels)
        {
            ans += hash[c - 'a'];
        }
        return ans;
    }
};