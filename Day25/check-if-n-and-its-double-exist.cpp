// LeetCode 1346
// Given an array arr of integers, check if there exist two indices i and j such that i != j, 0 <= i, j < arr.length, and arr[i] == 2 * arr[j]

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_map<int, int> hash;
        for (int num : arr)
        {
            if (hash.find(2 * num) != hash.end())
                return true;
            if ((num & 1) == 0)
                if (hash.find(num / 2) != hash.end())
                    return true;
            hash[num]++;
        }
        return false;
    }
};