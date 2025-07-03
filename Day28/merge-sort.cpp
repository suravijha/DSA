// Given a sequence of numbers ‘ARR’. Your task is to return a sorted sequence of ‘ARR’ in non-descending order with help of the merge sort algorithm.

void merge(vector<int> &arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    vector<int> left(n1);
    vector<int> right(n2);
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0;
    int index = start;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[index++] = left[i++];
        else
            arr[index++] = right[j++];
    }
    while (i < n1)
    {
        arr[index++] = left[i++];
    }
    while (j < n2)
    {
        arr[index++] = right[j++];
    }
}

void merge_sort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void mergeSort(vector<int> &arr, int n)
{
    merge_sort(arr, 0, n - 1);
}