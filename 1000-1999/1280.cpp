#include <bits/stdc++.h>
using namespace std;
int n, m, d[100010], found;
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    sort(d, d + n);
    cin >> m;
    for (int i = 0; i < n && !found; ++i)
    {
        int x = d[i], y = m - d[i];
        if (x >= y)
            break;
        int p = lower_bound(d + i + 1, d + n, y) - d;
        if (p < n && d[p] == y)
        {
            cout << x << " " << y << endl;
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "No" << endl;
    return 0;
}
