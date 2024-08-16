#include <bits/stdc++.h>
using namespace std;
int jz(int p, int b)
{
    int ret = 0, bb = 1;
    while (p)
    {
        if (p % 10 >= b)
            return -1;
        ret += p % 10 * bb;
        p /= 10;
        bb *= b;
    }
    return ret;
}
int main()
{
    int p, q, r, b, ans = 0;
    cin >> p >> q >> r;
    for (b = 2; b <= 16; ++b)
    {
        long long x = jz(p, b), y = jz(q, b), z = jz(r, b);
        if (x >= 0 && y >= 0 && z >= 0 && x * y == z)
        {
            ans = b;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
