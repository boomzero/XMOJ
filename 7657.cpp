#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+10;
long long n;
int k;
int a[N];
long long pos[N];
int count_step[2 * N], ans[N];
long long l = 0, r = 2e18;
long long count(long long m) {
    long long s = 0;
    for (int i = 0; i < k; ++i)
        s = min<long long>(s + (m + a[i] - 1) / a[i], 1e18);
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>k;
    for (int i = 0; i < k; ++i)
        cin >> a[i];
    while (l < r) {
        long long m = (l + r + 1) / 2;
        if (count(m) <= n) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    int res = n - count(l);
    for (int i = 0; i < k; ++i) {
        pos[i] = (l + a[i] - 1) / a[i] * a[i];
        if (pos[i] == l && res > 0) {
            --res;
            pos[i] += a[i];
        }
    }
    long long minpos = 2e18, maxpos = 0;
    for (int i = 0; i < k; ++i) {
        maxpos = max(maxpos, pos[i]);
        minpos = min(minpos, pos[i] - a[i]);
    }
    for (int i = 0; i < k; ++i) {
        for (long long j = pos[i] - a[i]; j >= minpos; j -= a[i])
            ++count_step[j - minpos];
        ans[i] = -count_step[pos[i] - a[i] - minpos];
    }
    for (int i = maxpos - minpos - 2; i >= 0; --i)
        count_step[i] += count_step[i + 1];
    for (int i = 0; i < k; ++i) {
        ans[i] += count_step[pos[i] - a[i] - minpos];
        cout << n - ans[i] << " \n"[i == k - 1];
    }
    cout<<endl;
    return 0;
}
