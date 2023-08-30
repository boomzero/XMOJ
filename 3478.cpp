#include <bits/stdc++.h>

using namespace std;

int n, a[200010];

long long ans;

int main()
{

    freopen("d.in", "r", stdin);

    freopen("d.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {

        cin >> a[i];

        a[i] -= i + 1;
    }

    sort(a, a + n);

    for (int i = 0; i < n; ++i)

        ans += abs(a[i] - a[n / 2]);

    cout << ans;

    return 0;
}
