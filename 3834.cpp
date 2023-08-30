#include <bits/stdc++.h>

using namespace std;

int n, m, ret[510][510];

int main()
{

    freopen("e.in", "r", stdin);

    freopen("e.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            char a;

            cin >> a;

            if (a == '#')
                ret[i][j] = 3;
        }
    }

    for (int i = 1; i < n - 1; i++)

        for (int j = 0; j < m; j++)

            ret[i][j] |= 1 << (j & 1);

    for (int i = 0; i < m; i++)
    {

        ret[0][i] |= 1;

        ret[n - 1][i] |= 2;
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)

            cout << (ret[i][j] & 1 ? '#' : '.');

        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)

            cout << (ret[i][j] & 2 ? '#' : '.');

        cout << endl;
    }

    return 0;
}
