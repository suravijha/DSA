// Function to count the frequency of all elements from 1 to N in the array.
vector<int> frequencyCount(vector<int>& arr) {
    vector<int> answer(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++) {
        answer[arr[i] - 1] += 1;
    }
    return answer;
}
