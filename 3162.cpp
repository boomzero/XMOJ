#include <bits/stdc++.h>
using namespace std;
int m, n, a[100010], mx;
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    a[n] = m + 1;
    mx = a[0] - 1;
    for (int i = 1; i <= n; ++i)
        if (a[i] - a[i - 1] - 1 > mx)
            mx = a[i] - a[i - 1] - 1;
    cout << mx;
    return 0;
}
