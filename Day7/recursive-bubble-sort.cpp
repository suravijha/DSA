void bubbleSort(vector<int>& arr, int n) {
  if (n == 1) return;
  int didSwap = 0;
  for (int j = 0; j <= n-2; j++) {
    if (arr[j] > arr[j + 1]) {
      int temp = arr[j + 1];
      arr[j + 1] = arr[j];
      arr[j] = temp;
      didSwap = 1;
    }
  }
  if (didSwap == 0) return;
  bubbleSort(arr, n - 1);
}
