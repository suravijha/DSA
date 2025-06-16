// Given an array of integers called nums, sort the array in non-decreasing order using the insertion sort algorithm and return the sorted array.
// A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && nums[j - 1] > nums[j])
        {
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
    return nums;
}
