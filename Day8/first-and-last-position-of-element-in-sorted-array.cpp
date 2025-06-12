pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int s = 0, e = n - 1, firstP = -1;
    int lastP = -1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k) {
            firstP = mid;
            e = mid - 1;
        } else if (arr[mid] < k) {
            s = mid + 1;
        } else if (arr[mid] > k) {
            e = mid - 1;
        }
    }
    s = 0;
    e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k) {
            lastP = mid;
            s = mid + 1;
        } else if (arr[mid] < k) {
            s = mid + 1;
        } else if (arr[mid] > k) {
            e = mid - 1;
        }
    }
    pair<int, int> ans = {firstP, lastP};
    return ans;
}
