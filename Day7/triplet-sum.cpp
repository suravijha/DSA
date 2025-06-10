vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        int tar = K - arr[i];
        int front = i + 1, back = n - 1;
        while (front < back) {
            int sum = arr[front] + arr[back];
            if (sum < tar) {
                front++;
            } else if (sum > tar) {
                back--;
            } else {
                ans.push_back({arr[i], arr[front], arr[back]});
                front++;
                back--;
                while (front < back && arr[front] == arr[front - 1]) front++;
                while (front < back && arr[back] == arr[back + 1]) back--;
            }
        }
    }
    return ans;
}
