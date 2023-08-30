#include <bits/stdc++.h>
using namespace std;
int n, m, a[110], ans;
char s[110][110], mx;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < m; ++i)
    {
        mx = 0;
        for (int j = 0; j < n; ++j)
            if (s[j][i] > mx)
                mx = s[j][i];
        for (int j = 0; j < n; ++j)
            if (s[j][i] == mx)
                a[j] = 1;
    }
    for (int i = 0; i < n; ++i)
        if (a[i])
            ++ans;
    cout << ans;
    return 0;
}
