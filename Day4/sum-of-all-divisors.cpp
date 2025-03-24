int sumOfAllDivisors(int n){
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += i * (n / i);
	}
	return ans;
}
