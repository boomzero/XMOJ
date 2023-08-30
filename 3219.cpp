#include <bits/stdc++.h>

using namespace std;

int n, m, x, a[110];

int main()
{

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {

        cin >> x;

        for (int j = x; j <= n; ++j)
        {

            if (a[j])

                break;

            a[j] = x;
        }
    }

    for (int i = 1; i <= n; ++i)

        cout << a[i] << " ";

    return 0;
}
