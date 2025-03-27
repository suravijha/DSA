vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int, int> freq;
    for (int num: v) {
        freq[num]++;
    }
    int minEle = v[0], maxEle = v[0];
    int minFreq = v.size(), maxFreq = 0;
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        int num = it->first;
        int count = it->second;
        if (count > maxFreq) {
            maxFreq = count;
            maxEle = num;
        } else if (count == maxFreq) {
            maxEle = min(maxEle, num);
        }
        if (count < minFreq) {
            minFreq = count;
            minEle = num;
        } else if (count == minFreq) {
            minEle = min(minEle, num);
        }
    }
    return {maxEle, minEle};
}
