// You are given an array of integers. You need to sort the array in ascending order using quick sort.

#include <bits/stdc++.h>
int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);
    while (start < pivotIndex && end > pivotIndex)
    {
        while (arr[start] <= pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < pivotIndex && end > pivotIndex)
            swap(arr[start++], arr[end--]);
    }
    return pivotIndex;
}
void quick_sort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int pi = partition(arr, start, end);
    quick_sort(arr, start, pi - 1);
    quick_sort(arr, pi + 1, end);
}
vector<int> quickSort(vector<int> arr)
{
    quick_sort(arr, 0, arr.size() - 1);
    return arr;
}
