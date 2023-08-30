#include <cstdio>
#include <iostream>
#include <string>
#define MAXN 1000000
using namespace std;
unsigned hs[MAXN + 5];
const unsigned b = 97;
int main()
{
    ios::sync_with_stdio(0);
    int q, n, m, ans;
    unsigned mul, hst;
    string s, t;
    cin >> q;
    while (q--)
    {
        cin >> t >> s;
        n = s.size();
        m = t.size();
        s = ' ' + s;
        t = ' ' + t;
        hst = 0;
        mul = 1;
        ans = 0;
        for (int i = 1; i <= n; ++i)
            hs[i] = hs[i - 1] * b + ((unsigned)s[i]);
        for (int i = 1; i <= m; ++i)
            mul *= b, hst = hst * b + ((unsigned)t[i]);
        for (int i = 0; i + m <= n; ++i)
        {
            // cout<<hst<<" "<<hs[i+m]-mul*hs[i]<<"\n";
            if (hs[i + m] - mul * hs[i] == hst)
                ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}
