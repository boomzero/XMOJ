#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("pow.in", "r", stdin);
    freopen("pow.out", "w", stdout);
    ll a, b;
    cin >> a >> b;
    ll ans = 1;
    for (int i = 0; i < b; ++i)
    {
        ans *= a;
        if (ans > 1000000000)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
