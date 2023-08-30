#include <bits/stdc++.h>

#include <vector>

using namespace std;

map<char, vector<char>> mp;

string st;

int k, l, c[10], mul_ch[110];

void dfs(char th)

{

    c[th - '0'] = 1;

    int sz = mp[th].size();

    for (int i = 0; i < sz; i++)

        if (!c[mp[th][i] - '0'])

            dfs(mp[th][i]);
}

int main()

{

    cin >> st >> k;

    l = st.length();

    for (int i = 1; i <= k; i++)

    {

        char x, y;

        cin >> x >> y;

        mp[x].push_back(y);
    }

    mul_ch[0] = 1;

    for (int i = 0; i < l; i++)

    {

        memset(c, 0, sizeof(c));

        dfs(st[i]);

        int sum = 0;

        for (int i = 0; i <= 9; i++)

            sum += c[i];

        int x = 0;

        for (int i = 0; i < 100; i++)

        {

            mul_ch[i] = mul_ch[i] * sum + x;

            x = mul_ch[i] / 10;

            mul_ch[i] %= 10;
        }
    }

    int i = 99;

    while (i > 0 && !mul_ch[i])

        i--;

    for (; i >= 0; i--)

        cout << mul_ch[i];

    cout << endl;

    return 0;
}
