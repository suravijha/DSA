// Given a number n, the task is to return the list/vector of the factorial numbers smaller than or equal to n.

#include <bits/stdc++.h>
using namespace std;

void storeFact(long long n, long long fact, int i, vector <long long> &ans) {
    if (fact > n) return;
    ans.push_back(fact);
    storeFact(n, fact * (i + 1), i + 1, ans);
}
vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;
    storeFact(n, 1, 1, ans);
    return ans;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<long long> result = factorialNumbers(n);
    cout << "Factorial numbers less than or equal to " << n << ": ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
