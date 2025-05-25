// You are given an integer n. Return the integer formed by placing the digits of n in reverse order.

int reverseNumber(int n) {
    int num = 0;
    while (n > 0) {
        num = num * 10 + n % 10;
        n /= 10;
    }
    return num;
}
