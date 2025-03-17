#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int dataTypeSize(string str) {
        if (str == "Character") 
            return 1;
        if (str == "Integer" || str == "Float") 
            return 4;
        if (str == "Long" || str == "Double") 
            return 8;
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
