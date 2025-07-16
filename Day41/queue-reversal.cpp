// You have been given a queue of ‘N’ distinct integers. For a given queue, you need to reverse all the elements in it.

#include <bits/stdc++.h> 
void reverse(queue < int > & q) {
    if (q.empty()) {
        return;
    }
    int first = q.front();
    q.pop();
    reverse(q);
    q.push(first);
}