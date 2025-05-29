// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
// Set bit: A set bit refers to a bit in the binary representation of a number that has a value of 1.

int hammingWeight(int n) {
    int ans = 0;
    while (n) {
        if (n & 1) {
            ans++;
        }
        n = n >> 1;
    }
    return ans;
}
