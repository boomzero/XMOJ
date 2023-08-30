#include <bits/stdc++.h>
using namespace std;
int n, a[55][55];
char c;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> c;
            if (c == '#')
                a[i][j] = 1;
        }
    for (int i = 2; i < n; ++i)
        for (int j = 2; j < n; ++j)
            if (a[i][j] == 0 && a[i - 1][j] == 0 && a[i + 1][j] == 0 && a[i][j - 1] == 0 && a[i][j + 1] == 0)
                a[i][j] = a[i - 1][j] = a[i + 1][j] = a[i][j - 1] = a[i][j + 1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] == 0)
            {
                cout << "NO";
                return 0;
            }
    cout << "YES";
    return 0;
}
