class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int start = 0;

        vector<string> ans;

        while (start < n) {
            int end = start;
            int count = 0;
            int total = 0;

            while (end < n && count + words[end].size() + (end - start) <= maxWidth) {
                count += words[end].size();
                total += words[end].size();
                end++;
            }

            int spaces = maxWidth - total;
            int gaps = end - start - 1;

            string curr = "";

            if (end == n || gaps == 0) {
                for (int i = start; i < end; i++) {
                    curr += words[i];

                    if (i != end - 1)
                        curr += " ";
                }

                while (curr.size() < maxWidth)
                    curr += " ";
            } else {
                int div = spaces / gaps;
                int extra = spaces % gaps;

                for (int i = start; i < end; i++) {
                    curr += words[i];

                    if (i != end - 1) {
                        int x = div + (extra > 0 ? 1 : 0);
                        curr += string(x, ' ');

                        if (extra > 0)
                            extra--;
                    }
                }
            }

            ans.push_back(curr);
            start = end;
        }
        
        return ans;
    }
};