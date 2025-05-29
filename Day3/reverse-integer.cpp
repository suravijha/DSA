// Given a signed 32-bit integer x, return x with its digits reversed. 
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

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
