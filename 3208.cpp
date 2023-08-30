#include <bits/stdc++.h>

using namespace std;

int n, m, a[10], b[10], c[10], x, y, ans;

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {

        cin >> x;

        a[x] = 1;

        ++c[x];
    }

    for (int i = 0; i < m; ++i)
    {

        cin >> x;

        b[x] = 1;

        ++c[x];
    }

    for (int i = 1; i < 10; ++i)

        if (c[i] == 2)
        {

            cout << i;

            return 0;
        }

    for (int i = 1; i < 10; ++i)

        if (a[i])
        {

            x = i;

            break;
        }

    for (int i = 1; i < 10; ++i)

        if (b[i])
        {

            y = i;

            break;
        }

    cout << min(x * 10 + y, x + y * 10);

    return 0;
}
