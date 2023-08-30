#include <bits/stdc++.h>

using namespace std;

int n, p = 1, a[110], ans;

int main()

{

    cin >> n;

    for (int i = 1; i < n; i++)
    {

        p = p + i;

        if (p > n)
        {

            p -= n;
        }

        a[p] = 1;
    }

    for (int i = 1; i <= n; i++)
    {

        if (a[i] == 1)
        {

            ans++;
        }
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++)
    {

        if (a[i] == 1)
        {

            cout << i << " ";
        }
    }

    return 0;
}
