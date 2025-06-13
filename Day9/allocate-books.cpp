// Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.
// There are ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
// If the allocation of books is not possible, return -1.

bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int student = 1;
    int page = 0;
    for (int i = 0; i < n; i++) {
        if (page + arr[i] <= mid) {
            page += arr[i];
        } 
        else {
            student++;
            if (student > m || arr[i] > mid) {
                return false;
            }
            page = arr[i];
        }
    }
    return true;
}
int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;
    int start = 0, end = 0;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        end += arr[i];
    }
    int mid = start + (end - start) / 2;
    while (start <= end) {
        if (isPossible(arr, n, m, mid)) {
            end = mid - 1;
            ans = mid;
        } 
        else {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
