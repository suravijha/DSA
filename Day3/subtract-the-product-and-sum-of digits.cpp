// Given an integer number n, return the difference between the product of its digits and the sum of its digits.

int subtractProductAndSum(int n) {
    int product = 1, sum = 0;
    while (n) {
        product *= n % 10;
        sum += n % 10;
        n /= 10;
    }
    return product - sum;
}
