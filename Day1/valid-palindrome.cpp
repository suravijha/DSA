// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

bool isPalindrome(string s) {
    string filtered;
    for (char c: s) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }
    return checkPalindrome(filtered, 0, filtered.size() - 1);
}
bool checkPalindrome(const string &s, int left, int right) {
    if (left >= right) return true;
    if (s[left] != s[right]) return false;
    return checkPalindrome(s, left + 1, right - 1);
}
