// For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

#include <bits/stdc++.h>
using namespace std;
long long getInversions(long long *arr, int n){
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] < arr[j]) ans++;
        }
    }
    return ans;
}