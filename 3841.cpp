#include <bits/stdc++.h>

#define int long long

#define endl "\n"

using namespace std;

const int inf = 1e18;

const int max_n = 2e3 + 100;

const int Mod = 924844033;

int n, k;

int p[max_n][max_n], m[2 * max_n][max_n], fact[max_n];

void fill()
{

    for (int len = 0; len < max_n; len++)
    {

        for (int t = 0; t < max_n; t++)
        {

            if (t == 0)
            {

                p[len][t] = 1;
            }
            else if (t >= len)
            {

                p[len][t] = 0;
            }
            else
            {

                p[len][t] = (p[len - 1][t] + p[len - 2][t - 1]) % Mod;
            }
        }
    }

    fact[0] = 1;

    for (int i = 1; i < max_n; i++)
    {

        fact[i] = (fact[i - 1] * i) % Mod;
    }

    return;
}

void get_m()
{

    m[2 * k][0] = 1;

    for (int i = 2 * k - 1; i >= 0; i--)
    {

        for (int t = 0; t <= n; t++)
        {

            int len = (n / k);

            if (2 * (n % k) > i)
                len++;

            for (int z = 0; z <= min(t, len); z++)
            {

                m[i][t] += (p[len][z] * m[i + 1][t - z]) % Mod;

                m[i][t] %= Mod;
            }
        }
    }

    return;
}

signed main()
{

    freopen("f.in", "r", stdin);

    freopen("f.out", "w", stdout);

    fill();

    cin >> n >> k;

    get_m();

    int ans = 0;

    for (int i = 0; i <= n; i++)
    {

        int c = (m[0][i] * fact[n - i]) % Mod;

        if (i % 2 == 0)
            ans = (ans + c) % Mod;

        else
            ans = (ans - c + Mod) % Mod;
    }

    cout << ans;
}
