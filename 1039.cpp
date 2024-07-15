#include <iostream>

using namespace std;
namespace lcod {
    bool lcod(int a, int b) {
        int diva[10001] = {0}, divb[10001] = {0}, ac = 0, bc = 0;
        for (int i = 2; i < a; i++) {
            if (a % i == 0) {
                ac++;
                diva[ac] = i;
            }
        }
        for (int i = 2; i < b; i++) {
            if (b % i == 0) {
                bc++;
                diva[bc] = i;
            }
        }
        for (int i = 1; i <= ac; i++) {
            for (int k = 1; k <= ac; k++) {
                if (diva[i] == divb[k]) return false;
            }
        }
        return true;
    }
}

int main() {
    freopen("ratio.in","r",stdin);
    freopen("ratio.out","w",stdout);
    int a, b, l, a1 = 1, b1 = 1;
    double minn = 0xfffff;
    cin >> a >> b >> l;
    for (int i = l; i > 0; i--) {
        for (int j = l; j > 0; j--) {
            if (!lcod::lcod(i, j)) {
                continue;
            }
            if ((double) i / (double) j < (double) a / (double) b) {
                continue;
            }
            if ((double) i / (double) j - (double) a / (double) b <= minn) {
                a1 = i, b1 = j;
                minn = (double) a1 / (double) b1 - (double) a / (double) b;
            }
        }
    }
    cout << a1 << " " << b1 << endl;
}
