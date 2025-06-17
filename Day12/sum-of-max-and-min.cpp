// You are given an array “ARR” of size N. Your task is to find out the sum of maximum and minimum elements in the array.

#include <bits/stdc++.h> 
int sumOfMaxMin(int arr[], int n){
	int min = arr[0], max = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}
	return min + max;
}