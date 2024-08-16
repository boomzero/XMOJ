#include <bits/stdc++.h>
using namespace std;
int a1, b1, c1, a2, b2, c2, ans;
int main()
{
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    if (a1 < a2)
    {
        ans += a2 - a1;
        b1 -= (a2 - a1) * 11;
        a1 = a2;
    }
    if (c1 < c2)
    {
        ans += (c2 - c1 + 8) / 9;
        b1 -= (c2 - c1 + 8) / 9;
        c1 += (c2 - c1 + 8) / 9 * 9;
    }
    if (b1 < b2 && a1 > a2)
    {
        if (b1 + (a1 - a2) * 9 < b2)
        {
            ans += (a1 - a2);
            b1 += (a1 - a2) * 9;
            a1 = a2;
        }
        else
        {
            ans += (b2 - b1 + 8) / 9;
            a1 -= (b2 - b1 + 8) / 9;
            b1 += (b2 - b1 + 8) / 9 * 9;
        }
    }
    if (b1 < b2)
    {
        if (b1 + (c1 - c2) / 11 >= b2)
        {
            ans += b2 - b1;
            b1 += b2 - b1;
            c1 -= (b2 - b1 + 10) / 11 * 11;
        }
    }
    if (b1 >= b2)
        cout << ans;
    else
        cout << -1;
    return 0;
}
