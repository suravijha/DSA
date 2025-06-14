// Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. 
// Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

bool isPossible(vector<int>& arr, int n, int k, int mid) {
    int painter = 1;
    int board = 0;
    for (int i = 0; i < n; i++) {
        if (board + arr[i] <= mid) {
            board += arr[i];
        } 
        else {
            painter++;
            if (painter > k || arr[i] > mid) {
                return false;
            }
            board = arr[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k) {
    int n = boards.size();
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        end+= boards[i];
    }
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossible(boards, n, k, mid)) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}
