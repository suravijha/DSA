// Leetcode 33
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.

int search(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[start] <= nums[mid]) {
            if (target >= nums[start] && target < nums[mid])
                end = mid - 1;
            else 
                start = mid + 1;
        } else {
            if (target > nums[mid] && target <= nums[end])
                start = mid + 1;
            else 
                end = mid - 1;
        }
    }
    return -1;
}
