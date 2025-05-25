/* You are given an integer 'n'. Return 'true' if 'n' is an Armstrong number, and 'false' otherwise.
An Armstrong number is a number (with 'k' digits) such that the sum of its digits raised to 'kth' power is equal to the number itself. */

bool checkArmstrong(int n){
	int temp = n;
	int result = 0;
	int digits = log10(n) + 1;
	while (n > 0) {
		int rem = n % 10;
		n /= 10;
		result += pow(rem, digits);
	}
	return (result == temp);
}
