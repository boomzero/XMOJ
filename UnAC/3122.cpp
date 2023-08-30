#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    int ans = 0;
    string in;
    cin >> in;
    for (char i : in)
    {
        if (i == '1')
            ans++;
    }
    cout << ans << endl;
    return 0;
}
