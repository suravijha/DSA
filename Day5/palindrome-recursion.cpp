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
