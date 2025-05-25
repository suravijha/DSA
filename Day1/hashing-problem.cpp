// Given an array of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. 
// If there are multiple elements that appear a maximum number of times, find the smallest of them.

int mostFrequentElement(vector<int>& nums) {
    unordered_map<int, int> maps;
    int freq = 0;
    int ans;
    for (int i = 0; i < nums.size(); i++) {
        maps[nums[i]]++;
    }
    for (auto x : maps) {
        if (x.second > freq) {
            freq = x.second;
            ans = x.first;
        }
    }
    return ans;
}
