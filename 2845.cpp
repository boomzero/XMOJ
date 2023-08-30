#include <bits/stdc++.h>

#define mp make_pair

using namespace std;

int read()
{

    char c;
    int x;
    while (c = getchar(), c < '0' || c > '9')
        ;
    x = c - '0';

    while (c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    return x;
}

int n, m, h, t, l, visk[55][55], visp[55][55];

pair<int, int> nxt[55][55][4];

char c[55][55], s[10005];

struct node
{

    int x, y, k, pa;
};

queue<node> q;

int main()

{

    n = read();
    m = read();

    register int i, j, k;

    memset(visk, -1, sizeof(visk));

    for (int i = 1; i <= n; i++)
    {

        scanf("%s", c[i] + 1);
    }

    scanf("%s", s + 1);

    l = 1;
    while (s[l])
        l++;
    s[l] = '*';

    for (i = 1; i <= n; i++)

        for (j = 1; j <= m; j++)
        {

            char s = c[i][j];

            for (k = i + 1; k <= n; k++)

                if (c[k][j] != s)
                {
                    nxt[i][j][0] = mp(k, j);
                    break;
                }

            for (k = i - 1; k; k--)

                if (c[k][j] != s)
                {
                    nxt[i][j][1] = mp(k, j);
                    break;
                }

            for (k = j + 1; k <= m; k++)

                if (c[i][k] != s)
                {
                    nxt[i][j][2] = mp(i, k);
                    break;
                }

            for (k = j - 1; k; k--)

                if (c[i][k] != s)
                {
                    nxt[i][j][3] = mp(i, k);
                    break;
                }
        }

    q.push((node){1, 1, 0, 0});

    while (!q.empty())
    {

        node e = q.front();
        q.pop();

        if (c[e.x][e.y] == s[e.k + 1])
        {

            q.push((node){e.x, e.y, e.k + 1, e.pa + 1});

            if (e.k + 1 == l)
            {

                printf("%d\n", e.pa + 1);
                exit(0);
            }
        }

        else
            for (i = 0; i < 4; i++)
            {

                pair<int, int> w = nxt[e.x][e.y][i];

                int fi = w.first, se = w.second;

                if (w.first == 0)
                    continue;

                if (visk[fi][se] < e.k)
                {

                    visk[fi][se] = e.k;

                    q.push((node){fi, se, e.k, e.pa + 1});
                }
            }
    }

    return 0;
}
