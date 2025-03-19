int reverse(int x) {
  long ans = 0;
  while (x != 0) {
    int rem = x % 10;
    ans = ans * 10 + rem;
    if ((ans >= INT_MAX) || (ans <= INT_MIN)) {
      return 0;
    }
    x /= 10;
  }
  return ans;
}
