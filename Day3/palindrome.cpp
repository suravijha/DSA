bool palindrome(int n)
{
    int num = n;
    int rev = 0;
    while (n != 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        if (rev == num) {
            return true;
        } else {
            return false;
        }
}
