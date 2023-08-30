#include <bits/stdc++.h>

using namespace std;

int n, ans;

string word[1000], beginn;

int vis[1000];

bool check(string s, string m, int k)
{

    int lens = s.length();

    for (int i = 0; i < k; i++)
    {

        if (s[lens - k + i] != m[i])

            return false;
    }

    return true;
}

void add(string &s, string m, int k)
{

    int lenm = m.length();

    for (int i = k; i < lenm; i++)

        s += m[i];
}

void dfs(string now)
{

    int x = now.length();

    ans = max(ans, x);

    for (int i = 1; i <= n; i++)
    {

        if (vis[i] >= 2)

            continue;

        int maxk = word[i].length();

        for (int j = 1; j <= maxk; j++)
        {

            if (check(now, word[i], j))
            {

                string temp = now;

                add(temp, word[i], j);

                if (temp == now)

                    continue;

                vis[i]++;

                dfs(temp);

                vis[i]--;
            }
        }
    }
}

int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)

        cin >> word[i];

    cin >> beginn;

    dfs(beginn);

    cout << ans;

    return 0;
}
