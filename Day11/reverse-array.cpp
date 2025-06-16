// Given an array 'arr' of size 'n'.
// Return an array with all the elements placed in reverse order.

#include <bits/stdc++.h>
using namespace std;

vector<int> reverseArray(int n, vector<int> &nums)
{
    int i = 0, j = n - 1;
    while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    return nums;
}