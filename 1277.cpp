#include <bits/stdc++.h>
using namespace std;
int n, k, d[10010], l = 1, r = -1;
int main()
{
    double tmp;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        d[i] = int(tmp * 100);
        r = max(d[i], r);
    }
    while (l <= r)
    {
        int mid = (l + r) / 2;
        long long num = 0;
        for (int i = 0; i < n; ++i)
        {
            num += d[i] / mid;
        }
        if (num >= k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (r == 0)
        cout << "0.00" << endl;
    else
        cout << setprecision(2) << fixed << r / 100.0;
    return 0;
}
