/* You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. 
You need to find the sum of these two numbers and return this sum in the form of an array.
Note:
1. The length of each array is greater than zero.
2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.
3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros. */

#include <bits/stdc++.h> 
vector<int> reverse(vector<int> v) {
    int start = 0;
    int end = v.size()-1;
    while(start < end)
    {
        swap(v[start++], v[end--]);
    }
    return v;
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int i = n - 1;
	int j = m - 1;
	vector<int> ans;
	int carry = 0;
	while (i >= 0 && j >= 0) {
		int sum = a[i] + b[j] + carry;
		carry = sum / 10;
		sum %= 10;
		ans.push_back(sum);
		i--;
		j--;
	}
	while (i >= 0) {
		int sum = a[i] + carry;
		carry = sum / 10;
		sum %= 10;
		ans.push_back(sum);
		i--;
	} 
	while (j >= 0) {
		int sum = b[j] + carry;
		carry = sum / 10;
		sum %= 10;
		ans.push_back(sum);
		j--;
	}
	while (carry) {
		int sum = carry % 10;
		carry /= 10;
		ans.push_back(sum);
	}
	return reverse(ans);
}