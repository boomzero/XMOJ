#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, ans;
char s[55];
int map[1010][55], tmp[5][5][5];
int work(char c)
{
    if (c == 'A')
        return 1;
    if (c == 'T')
        return 2;
    if (c == 'G')
        return 3;
    if (c == 'C')
        return 4;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%s", s);
        for (int j = 0; j < m; j++)
            map[i][j + 1] = work(s[j]);
    }
    for (int i = 1; i <= m - 2; i++)
        for (int j = i + 1; j <= m - 1; j++)
            for (int k = j + 1; k <= m; k++)
            {
                bool flag = 0;
                memset(tmp, 0, sizeof(tmp));
                for (int l = 1; l <= n; l++)
                    tmp[map[l][i]][map[l][j]][map[l][k]] = 1;
                for (int l = n + 1; l <= 2 * n; l++)
                    if (tmp[map[l][i]][map[l][j]][map[l][k]])
                    {
                        flag = 1;
                        break;
                    }
                if (!flag)
                    ans++;
            }
    cout << ans;
}
