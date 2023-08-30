#include <bits/stdc++.h>

using namespace std;

long long n, q, t, cnt, t1, mx;

int main()
{

    cin >> n;

    for (int i = 0; i < n; ++i)
    {

        cin >> t >> cnt;

        if (q)
        {

            q -= t - t1;

            if (q < 0)

                q = 0;
        }

        q += cnt;

        if (q > mx)

            mx = q;

        t1 = t;
    }

    if (q > 0)

        t1 += q;

    cout << t1 << " " << mx;

    return 0;
}
