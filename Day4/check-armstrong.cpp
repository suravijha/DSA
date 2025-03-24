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
