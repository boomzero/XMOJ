#include <bits/stdc++.h>

using namespace std;
map<string, bool> f;

int main() {
    f["xiaoming"] = true;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        if (!f.count(a)) f[a] = false;
        if (!f.count(b)) f[b] = false;
        if (f[a] || f[b]) f[a] = f[b] = true;
    }
    int c = 0;
    for (auto i: f) {
        if (i.second) c++;
    }
    cout << c << endl;
    return 0;
}
