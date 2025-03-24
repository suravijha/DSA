// Print 1 to n without loop
int count = 0;
void printNos(int n) {
    count++;
    cout << count << " ";
    if (count == n) return;
    printNos(n);
}

// Print name n times
int count = 0;
void printName(int N) {
    count++;
    cout << "Suravi ";
    if (count == N) return;
    printName(N);
}

// Print N to 1
void printNos(int N) {
    cout << N << " ";
    if (N == 1) return;
    printNos(N-1);
}
