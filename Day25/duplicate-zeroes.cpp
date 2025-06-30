// LeetCode 1089
// Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
// Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        int zeros = 0;
        for (int i = 0; i + zeros < n; i++)
        {
            if (arr[i] == 0)
            {
                if (i + zeros == n - 1)
                {
                    arr[n - 1] = 0;
                    n--;
                    break;
                }
                zeros++;
            }
        }
        for (int i = n - 1 - zeros; i >= 0; --i)
        {
            if (arr[i] == 0)
            {
                arr[i + zeros] = 0;
                zeros--;
                arr[i + zeros] = 0;
            }
            else
            {
                arr[i + zeros] = arr[i];
            }
        }
    }
};