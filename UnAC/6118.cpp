#include <iostream>
#include <cmath>
using namespace std;
int main() {
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    int n;
    cin >> n;
    int w[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    int s1 = w[1];
    int s2 = 0;
    for (int i = 2; i <= n; ++i) {
        s2 += w[i];
    }
    int minVal = abs(s1 - s2), minPos = 1;
    for (int i = 2; i <= n; ++i) {
        s1 += w[i], s2 -= w[i];
        if (abs(s1 - s2) < minVal) {
            minVal = abs(s1 - s2);
            minPos = i;
        }
    }
    cout << minVal << endl;
    return 0;
}
