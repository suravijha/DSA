// Given an array of integers called nums,sort the array in non-decreasing order using the bubble sort algorithm and return the sorted array.
// A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

vector<int> bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--) {
        int swap = 0;
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                swap = 1;
            }
        }
        if (swap == 0) {
            break;
        }
    }
    return nums;
}
