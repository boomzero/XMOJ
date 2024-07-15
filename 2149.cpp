#include <bits/stdc++.h>

#define int long long
using namespace std;
int mod;

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
} base, proc, orb;

void init() {
    base[1][1] = base[1][2] = base[2][1] = orb[1][1] = orb[1][2] = orb[2][1] = proc[1][1] = proc[1][2] = 1;
}

mat qpow(mat a, int n) {
    if (n == 1) return a;
    if (n % 2 == 0) {
        mat tmp = qpow(a, n / 2);
        return tmp * tmp;
    } else {
        mat tmp = qpow(a, n / 2);
        return tmp * tmp * orb;
    }
}

signed main() {
    init();
    int n;
    cin >> n >> mod;
    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }
    mat tmp = qpow(base, n - 2);
    cout << (tmp[1][1] + tmp[2][1]) % mod << endl;
    return 0;
}


