#include <bits/stdc++.h>
using namespace std;
int n, a[110], s, t, tot, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        tot += a[i];
    }
    cin >> s >> t;
    if (s > t)
        swap(s, t);
    for (int i = s; i < t; ++i)
        ans += a[i];
    cout << min(ans, tot - ans);
    return 0;
}
