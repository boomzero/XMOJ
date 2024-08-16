#include <bits/stdc++.h>
using namespace std;
int n, a[60][60];
bool isOk(int i, int j)
{
    for (int p = 0; p < n; ++p)
        for (int q = 0; q < n; ++q)
            if (a[i][p] + a[q][j] == a[i][j])
                return true;
    return false;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j] != 1 && !isOk(i, j))
            {
                cout << "NO";
                return 0;
            }
    cout << "YES";
    return 0;
}
