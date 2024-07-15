#include <bits/stdc++.h>

using namespace std;
int n;
int a[50005], in[50005], tmp[50005];

int lb(int x) {
    return x & (-x);
}

int main() {
    int t = 1;
    scanf("%d", &t); // NOLINT(*-err34-c)
    for (int some_stupid_random_var_that_is_only_used_once_in_a_for_loop_and_pollutes_the_whole_scope = 0;
         some_stupid_random_var_that_is_only_used_once_in_a_for_loop_and_pollutes_the_whole_scope <
         t; ++some_stupid_random_var_that_is_only_used_once_in_a_for_loop_and_pollutes_the_whole_scope) {
        memset(a, 0, sizeof(a));
        scanf("%d", &n); // NOLINT(*-err34-c)
        int ans = 0;
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
        printf("%d\n", ans);
    }
    return 0;
}
