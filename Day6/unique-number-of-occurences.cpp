// Leetcode 1207
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map <int, int> map;
    for (int i = 0; i < arr.size(); i++) {
        map[arr[i]]++;
    }
    set <int> occ;
    for (auto x:map) {
        occ.insert(x.second);
    }
    return occ.size() == map.size();
}
