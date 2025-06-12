int count(vector<int>& arr, int n, int x) {
	int s = 0, e = n - 1, firstP = -1, lastP = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) {
            firstP = mid;
            e = mid - 1;
        } else if (arr[mid] < x) {
            s = mid + 1;
        } else if (arr[mid] > x) {
            e = mid - 1;
        }
    }
    if (firstP == -1) return 0;
    s = 0;
    e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x) {
            lastP = mid;
            s = mid + 1;
        } else if (arr[mid] < x) {
            s = mid + 1;
        } else if (arr[mid] > x) {
            e = mid - 1;
        }
    }
	return lastP - firstP + 1;
}
