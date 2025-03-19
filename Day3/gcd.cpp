int calcGCD(int n, int m){
    while (n > 0 && m > 0) {
        if (n > m) {
            n %= m;
        } else {
            m %= n;
        }
    }
    if (m == 0) {
        return n;
    }
    return m;
}
