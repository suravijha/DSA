class Solution {
private:
    void update(vector<int>& bit, int i) {
        while (i < bit.size()) {
            bit[i]++;
            i += i & (-i);
        }
    }
    
    int query(vector<int>& bit, int i) {
        int sum = 0;
        
        while (i > 0) {
            sum += bit[i];
            i -= i & (-i);
        }
        
        return sum;
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> sorted = nums;        
        sort(sorted.begin(), sorted.end());
        
        sorted.erase(
            unique(sorted.begin(), sorted.end()),
            sorted.end()
        );
        
        vector<int> bit(sorted.size() + 1, 0);
        
        vector<int> counts(n);
        
        for (int i = n - 1; i >= 0; i--) {
            
            int rank = lower_bound(
                sorted.begin(),
                sorted.end(),
                nums[i]
            ) - sorted.begin() + 1;
            
            counts[i] = query(bit, rank - 1);
            
            update(bit, rank);
        }
        
        return counts;
    }
};