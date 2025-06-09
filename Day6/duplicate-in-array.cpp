int findDuplicate(vector<int> &arr) {
    int sum = (arr.size() - 1) * arr.size() / 2;
    int arrsum = 0;
    for (int i = 0; i < arr.size(); i++) {
        arrsum += arr[i];
    }
    return arrsum - sum;	
}
