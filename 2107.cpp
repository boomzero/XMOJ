#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 25100;

int a[N];

bool vis[M];

int main()
{

    freopen("money.in", "r", stdin);

    freopen("money.out", "w", stdout);

    int T;

    cin >> T;

    while (T--)
    {

        memset(vis, false, sizeof(vis));

        int maxn = 0, ans = 0;

        int n;

        cin >> n;

        for (int i = 1; i <= n; ++i)
        {

            cin >> a[i];

            maxn = max(maxn, a[i]);
        }

        sort(a + 1, a + n + 1);

        for (int i = 1; i <= n; ++i)
        {

            if (vis[a[i]])
            {

                continue;
            }

            vis[a[i]] = true;

            ++ans;

            for (int j = a[i]; j <= maxn; ++j)
            {

                if (vis[j - a[i]])
                {

                    vis[j] = true;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
