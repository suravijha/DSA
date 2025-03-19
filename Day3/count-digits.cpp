// Function to return the number of digits in 'n' that evenly divide 'n'.
int countDigits(int n){
	int count = 0;
	int num = n;
	while (num > 0) {
		int rem = num % 10;
		if (rem != 0) {
			count += (n % rem == 0);
		}
		num = num / 10;
	}	
	return count;
}
