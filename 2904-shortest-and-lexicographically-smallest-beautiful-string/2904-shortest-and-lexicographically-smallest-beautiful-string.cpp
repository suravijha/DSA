class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int ones = 0;

        int len = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            while (ones > k) {
                if (s[left] == '1') 
                    ones--;

                left++;
            }

            if (ones == k) {
                while (left <= right && s[left] == '0')
                    left++;

                int cur = right - left + 1;

                if (cur < len) {
                    len = cur;
                    ans = s.substr(left, len);
                } else if (cur == len) {
                    string temp = s.substr(left, len);
                    
                    if (temp < ans)
                        ans = temp;
                }
            }
        }

        return ans;
    }
};