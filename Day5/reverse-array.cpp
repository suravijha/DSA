#include <bits/stdc++.h>
using namespace std;

void reverseHelper(vector <int> &arr, int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverseHelper(arr, start + 1, end - 1);
}
void reverseArray(vector<int> &arr) {
    reverseHelper(arr, 0, arr.size() - 1);
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
