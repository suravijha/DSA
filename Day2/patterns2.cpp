void pattern12(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        for (int j = 1; j <= 2*n-2*i; j++) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern13(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void pattern14(int n) {
    for (char i = 'A'; i < 'A'+n; i++) {
        for (char j = 'A'; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern15(int n) {
    for (int i = 1; i <= n; i++) {
        for (char j = 'A'; j < 'A'+char(n-i+1); j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern16(int n) {
    for (char i = 'A'; i < 'A'+n; i++) {
        for (char j = 'A'; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void pattern17(int n) {
    for (int i = 0; i < n; i++) {
        char ch = 'A';
        for (int j = 0; j < n-i-1; j++) {
            cout << "  ";
        }
        for (int j = 0; j < 2*i+1; j++) {
            cout << ch << " ";
            if (j < i) ch++;
            else ch--;
        }
        for (int j = 0; j < n-i-1; j++) {
            cout << "  ";
        }
        cout << endl;
    }
}

void pattern18(int n) {
    for (int i = 0; i < n; i++) {
        char ch = 'A'+n-1;
        for (int j = 0; j <= i; j++) {
            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
}

void pattern19(int n) {
    int spaces = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            cout << "* ";
        }
        for (int j = 0; j < spaces; j++) {
            cout << "  ";
        }
        for (int j = 0; j < n-i; j++) {
            cout << "* ";
        }
        cout << endl;
        spaces = spaces + 2;
    }
    spaces = 2 * n - 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        for (int j = 0; j < spaces; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
        spaces = spaces - 2;
    }
}

void pattern20(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        for (int j = 0; j < 2*n-2*i-2; j++) {
            cout << "  ";
        } 
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            cout << "* ";
        }
        for (int j = 0; j < 2*i; j++) {
            cout << "  ";
        }
        for (int j = 0; j < n-i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern21(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i==1 || j==1 || i==n || j==n) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

void pattern22(int n) {
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = 0; j < 2*n-1; j++) {
            int top = i;
            int left = j;
            int bottom = 2 * n - i - 2;
            int right = 2 * n - j - 2;
            int value = min(min(top, left), min(bottom, right));
            cout << n - value;
        }
        cout << endl;
    }
}
