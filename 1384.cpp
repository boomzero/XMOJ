#include <bits/stdc++.h>

#define int long long
using namespace std;
int n;
int a[100005], in[100005], tmp[100005];

int lb(int x) {
    return x & (-x);
}

signed main() {
    int t = 0;
    cin >> t;
    for (int qwq = 0; qwq < t; ++qwq) {

        memset(a, 0, sizeof(a));
        scanf("%d", &n); // NOLINT(*-err34-c)
        int ans = 0, mans, tans;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &in[i]); // NOLINT(*-err34-c) //shut up, linter
            tmp[i] = in[i]; //we might as well do the copying here
        }
        sort(tmp + 1, tmp + 1 + n);
        unordered_map<int, int> idx;
        for (int i = 1; i <= n; ++i) {
            idx[tmp[i]] = i;
        }
        for (int i = 1; i <= n; ++i) {
            in[i] = idx[in[i]];
        }
        //at this point, all the data is relabeled
        for (int i = 1; i <= n; ++i) {
            //We should check how many numbers are greater than this,
            //but we can't,
            //so,
            //we check how many numbers are smaller than this
            int lsCnt = 0; //We'll store that here.
            int fetch = in[i]; //this is just a small var that I need to keep track of
            while (fetch > 0) {
                lsCnt += a[fetch];
                fetch -= lb(fetch);
            }
            //ok, now?
            ans += (i - lsCnt - 1);
            //anyway, we still need to upd a[]
            int updPt = in[i];
            while (updPt <= n) {
                a[updPt]++;
                updPt += lb(updPt);
            }
        }
        mans = tans = ans;
        for (int i = 1; i <= n; ++i) {
            tans += (n - in[i]);
            tans -= (in[i] - 1);
            mans = min(mans, tans);
        }
        printf("%lld\n", mans);
    }
    return 0;
}
