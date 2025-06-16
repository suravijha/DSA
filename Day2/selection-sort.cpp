// Given an array of integers nums, sort the array in non-decreasing order using the selection sort algorithm and return the sorted array.
// A sorted array in non-decreasing order is an array where each element is greater than or equal to all previous elements in the array.

#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (nums[j] < nums[min])
                min = j;
        }
        swap(nums[i], nums[min]);
    }
    return nums;
}
