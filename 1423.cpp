#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<pair<int, int>> in;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        in.push_back({tmp, i + 1});
        stable_sort(in.begin(), in.end());
    }

    bool f = true;
    for (auto i: in) {
        if (!f) cout << " ";
        f = false;
        cout << i.second;
    }
    for (int i = 0; i < in.size(); ++i) {
        sum += in[i].first * (n - i - 1);
    }
//    for (int i: in) {
//        sum += sum;
//        sum += i;
//    }
    cout << endl;
    printf("%.2f", ((double) sum) / n);
    return 0;
}
