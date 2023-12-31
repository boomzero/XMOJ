#include <iostream>
using namespace std;
const int MAX = 100010;
int n, a[MAX], f[MAX], len;
int main()
{
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    len = 1;
    f[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        int pos = lower_bound(f, f + len, a[i]) - f;
        f[pos] = a[i];
        len = max(len, pos + 1);
    }
    cout << len;
}
