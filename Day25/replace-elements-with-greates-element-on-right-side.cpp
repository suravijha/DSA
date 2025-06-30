// LeetCode 1299
// Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
// After doing so, return the array.

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            swap(maxi, arr[i]);
            maxi = max(arr[i], maxi);
        }
        return arr;
    }
};