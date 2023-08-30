#include <bits/stdc++.h>

using namespace std;

int n, x, ans[110], cnt, days, neg;

int main()
{

    cin >> n;

    for (int i = 0; i < n; ++i)
    {

        cin >> x;

        if (x < 0)
        {

            ++neg;

            if (neg == 3)
            {

                ans[cnt] = days;

                ++cnt;

                days = 0;

                neg = 1;
            }
        }

        ++days;
    }

    ans[cnt] = days;

    ++cnt;

    cout << cnt << endl;

    for (int i = 0; i < cnt; ++i)

        cout << ans[i] << " ";

    return 0;
}
