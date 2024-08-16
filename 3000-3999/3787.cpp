#include <bits/stdc++.h>

using namespace std;
namespace IN {
    typedef unsigned uint;
    uint a, b, c, d;

    void init(uint A, uint B, uint C, uint D) {
        a = A, b = B, c = C, d = D;
    }

    uint rand() {
        c = (long long) c * b % a;
        return c;
    }

    void Getop(int &type, int &x) {
        type = rand() / 10 % 3 + 1;
        x = rand() % d + 1;
    }
}
inline void write(long long x)
{
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    long long n, a, b, c, d;
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> c >> d;
    IN::init(a, b, c, d);
    set<long long> f;
    f.insert(0);
    f.insert(10000001);
    for (int i = 0; i < n; ++i) {
        int tp, x;
        IN::Getop(tp, x);
        if (tp == 1) {
            f.insert(x);
        } else if (tp == 2) {
            auto p = f.lower_bound(x);
            p--;
            write(*p);
            putchar('\n');
        } else {
            write(*f.upper_bound(x));
            putchar('\n');
        }
    }
    return 0;
}

