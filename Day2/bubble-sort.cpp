// Given an array of integers called nums,sort the array in non-decreasing order using the bubble sort algorithm and return the sorted array.
// A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
            break;
    }
    return nums;
}
