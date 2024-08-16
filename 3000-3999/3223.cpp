#include <bits/stdc++.h>
using namespace std;
int n, st = 1;
int ans;
bool p[110];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        st = st + i;
        if (st > n)
        {
            st -= n;
        }
        p[st] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] == false)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
