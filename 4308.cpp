#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 9;

const int inf = 1e9 + 9;

ll n, a[maxn], b[maxn], r[maxn];

vector<ll> s[maxn];

bool ok(ll m)
{

    //  cout<<m<<'\n';

    for (int i = 1; i <= n; i++)

        s[i].clear(), r[i] = inf;

    for (int i = 1; i <= m; i++)

        b[i] = a[i];

    sort(b + 1, b + 1 + m);

    ll pos = 1, k = 0, frst = 1;

    for (int i = 1; i <= m; i++)
    {

        ll id = lower_bound(r + frst, r + 1 + k, a[i]) - r;

        if (id > k)
            k++;

        r[id] = a[i];

        s[id].push_back(a[i]);

        if (id > frst && a[i] < s[id - 1][0])
        {

            //          cout<<a[i]<<'\n';

            return 0;
        }

        while (r[frst] == b[pos] && frst <= k)
        {

            pos++;

            //          cout<<r[frst]<<' ';

            s[frst].pop_back();

            while (s[frst].empty() && frst <= k)

                r[frst] = 0, frst++;

            if (frst <= k)

                r[frst] = s[frst][s[frst].size() - 1];
        }
    }

    while (frst <= k && r[frst] == b[pos])
    {

        pos++;

        s[frst].pop_back();

        //      cout<<r[frst]<<' ';

        while (s[frst].empty() && frst <= k)

            r[frst] = 0, frst++;

        if (frst <= k)

            r[frst] = s[frst][s[frst].size() - 1];
    }

    //  cout<<'\n';

    return (frst > k);
}

int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int l = 1, r = n, ans = 0, mid;

    while (l <= r)
    {

        mid = l + (r - l) / 2;

        if (ok(mid))
            ans = mid, l = mid + 1;

        else
            r = mid - 1;
    }

    cout << ans;

    return 0;
}
