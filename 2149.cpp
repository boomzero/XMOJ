#include <bits/stdc++.h>

#define int long long
using namespace std;
int mod = 1000000007;

struct mat {
    int a[3][3] = {0};

    int *operator[](const int id) {
        return a[id];
    }

    mat operator*(mat b) {
        mat res;
        for (int i = 1; i <= 2; ++i) {
            for (int j = 1; j <= 2; ++j) {
                for (int k = 1; k <= 2; ++k) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
                }
            }
        }
        return res;
    }
} base;

mat qpow(mat a, int n) {
    if (n == 1) return a;
    if (n % 2 == 0) {
        mat tmp = qpow(a, n / 2);
        return tmp * tmp;
    } else {
        mat tmp = qpow(a, n / 2);
        return tmp * tmp * base;
    }
}

signed main() {
    int p, n;
    cin >> p >> n;
    base[1][2] = p - 1;
    base[2][1] = 1;
    base[2][2] = p - 2;
    mat tmp = qpow(base, n);
    cout << (tmp[1][1]) % mod << endl;
    return 0;
}
