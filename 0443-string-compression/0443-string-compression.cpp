class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int index = 0;

        int n = chars.size();

        while (i < n) {
            int count = 1;
            
            while (i + count < n && chars[i] == chars[i + count])
                count++;

            chars[index++] = chars[i];

            if (count > 1) {
                for (char c: to_string(count)) {
                    chars[index++] = c;
                }
            }
            
            i += count;
        }
        return index;
    }
};