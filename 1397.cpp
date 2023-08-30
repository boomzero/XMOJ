#include <bits/stdc++.h>
using namespace std;
vector<int> p;
int main() {
    int w, n;
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        p.emplace_back(tmp);
    }
    sort(p.begin(), p.end());
    int ans = 0;
    while (!p.empty()) {
        int begin = p[0], end = p[p.size() - 1];
        if (begin + end <= w) {
            p.erase(p.begin());
            ans++;
            if(!p.empty())
                p.pop_back();
        } else {
            ans++;
            p.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}
