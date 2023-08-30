#include <bits/stdc++.h>

using namespace std;

int n, a[100010], minn, lastn = -1, ans;

int main()
{

    cin >> n >> a[1];

    minn = a[1];

    for (int i = 2; i <= n; ++i)
    {

        cin >> a[i];

        if (minn > a[i])

            minn = a[i];
    }

    ans = n;

    for (int i = 1; i <= n; ++i)

        if (a[i] == minn)
        {

            if (lastn != -1 && ans > i - lastn)

                ans = i - lastn;

            lastn = i;
        }

    cout << ans;

    return 0;
}
