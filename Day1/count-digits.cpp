// You are given an integer n. You need to return the number of digits in the number.

int countDigit(int n) {
  int result = 0;
  while (n > 0) {
    result++;
    n /= 10;
  }
  return result;
}
