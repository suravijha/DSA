// Given an array and a positive integer k, find the first negative integer for each window(contiguous subarray) of size k. If a window does not contain a negative integer, then print 0 for that window.

#include <bits/stdc++.h>
vector<int> firstNegative(vector<int> arr, int n, int k) {
	vector<int> ans;
	deque<int> dq;

	for (int i = 0; i < k; i++) {
		if (arr[i] < 0)
			dq.push_back(i);
	}

	for (int i = k; i < n; i++) {
		if (!dq.empty())
			ans.push_back(arr[dq.front()]);
		else
			ans.push_back(0);

		while (!dq.empty() && dq.front() <= i - k) {
			dq.pop_front();
		}

		if (arr[i] < 0)
			dq.push_back(i);
	}

	if (!dq.empty())
		ans.push_back(arr[dq.front()]);
	else
		ans.push_back(0);
		
	return ans;
}