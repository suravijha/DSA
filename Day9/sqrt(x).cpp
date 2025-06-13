// Leetcode 69
// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
// You must not use any built-in exponent function or operator.

int mySqrt(int x) {
    int start = 0, end = x;
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if ((long) mid * mid > (long) x) {
            end = mid - 1;
        } else if (mid * mid == x) {
            return mid;
        } else {
            start = mid + 1;
        }
    }
    return end;
}
