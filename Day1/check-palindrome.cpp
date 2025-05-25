// You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.
// A palindrome number is a number which reads the same both left to right and right to left.

bool isPalindrome(int n) {
    int num = 0;
    int temp = n;
    while (n > 0) {
        num = num * 10 + n % 10;
        n /= 10;
    }
    return num == temp;
}
