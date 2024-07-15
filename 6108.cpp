#include <iostream>

using namespace std;
int v[100] = {0}, c[100] = {0};

int main() {
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i] >= c[i]) {
            x += v[i];
            y += c[i];
        }
    }
    cout << x - y << endl;
    return 0;
}

