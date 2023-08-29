#include <bits/stdc++.h>

const int maxn = 100005;
using namespace std;
bool isPrime[maxn];

void eratos(int n) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i) {
        isPrime[i] = true;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
    eratos(n + 1);
    for (int i = 2; i <= n + 1; ++i) {
        if (isPrime[i]) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << endl;
    return 0;
}

