#include <bits/stdc++.h>

using namespace std;

int d[20][20], bid[20][20], ans;

bool r[20][20], c[20][20], b[20][20];

bool dfs(int x, int y)
{

    if (d[x][y] > 0)
        return dfs(x, y + 1);

    if (y == 10)
        return dfs(x + 1, 1);

    if (x == 10)
    {

        ans += d[1][1] * 100 + d[1][2] * 10 + d[1][3];

        return true;
    }

    for (int i = 1; i <= 9; i++)
    {

        if (!r[x][i] && !c[y][i] && !b[bid[x][y]][i])
        {

            d[x][y] = i;

            r[x][i] = c[y][i] = b[bid[x][y]][i] = 1;

            if (dfs(x, y + 1))
                return true;

            r[x][i] = c[y][i] = b[bid[x][y]][i] = 0;

            d[x][y] = 0;
        }
    }

    return false;
}

int main()
{

    for (int i = 1; i <= 9; i++)

        for (int j = 1; j <= 9; j++)

            bid[i][j] = ((i - 1) / 3) * 3 + (j - 1) / 3 + 1;

    int T;
    scanf("%d", &T);

    char s[20];

    while (T--)
    {

        memset(r, 0, sizeof(r));

        memset(c, 0, sizeof(c));

        memset(b, 0, sizeof(b));

        for (int i = 1; i <= 9; i++)
        {

            scanf("%s", s);

            for (int j = 1, dd; j <= 9; ++j)
            {

                d[i][j] = dd = s[j - 1] - '0';

                r[i][dd] = c[j][dd] = b[bid[i][j]][dd] = 1;
            }
        }

        dfs(1, 1);
    }

    printf("%d\n", ans);

    return 0;
}
