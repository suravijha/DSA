void sort012(int *arr, int n) {
   int current = 0, front = 0, back = n - 1;
   while (current <= back) {
      if (arr[current] == 0) {
         swap(arr[front], arr[current]);
         front++;
         current++;
      } else if (arr[current] == 1) {
         current++;
      } else {
         swap(arr[current], arr[back]);
         back--;
      }
   }
}
