#include <bits/stdc++.h>
using namespace std;
int n, m[110][110], answer[110][110];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &m[i][j]);
    memset(answer, 0x3f3f3f3f, sizeof(answer));
    answer[1][1] = m[1][1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != 1 || j != 1)
                answer[i][j] = min(answer[i - 1][j], answer[i][j - 1]) + m[i][j];
    printf("%d\n", answer[n][n]);
    return 0;
}
// zuiditongxinfei
