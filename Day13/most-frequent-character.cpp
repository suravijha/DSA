// Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. 
// If more than one character occurs the maximum number of times then print the lexicographically smaller character.

class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        // Your code here
        map<char, int> maps;
        int freq = 0;
        char ans = s[0];
        for (int i = 0; i < s.size(); i++) {
            maps[s[i]]++;
        }
        for (auto x : maps) {
            if (x.second > freq) {
                freq = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
};