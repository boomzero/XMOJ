#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000010;
int n, v1[MAX], v2[MAX], c[MAX][2], cc, pos1[MAX], pos2[MAX], len, f[MAX];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v1[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &v2[i]);
    for (int i = 1; i <= n; ++i)
        pos1[v1[i]] = pos2[v2[i]] = i;
    for (int i = 1; i <= n; ++i)
    {
        if (v1[i] != i)
        {
            c[cc][0] = i;
            c[cc][1] = v1[i];
            int tmp = v1[i];
            swap(v1[pos1[tmp]], v1[pos1[i]]);
            swap(pos1[tmp], pos1[i]);
            ++cc;
        }
    }
    for (int i = 0; i < cc; ++i)
    {
        swap(v2[pos2[c[i][0]]], v2[pos2[c[i][1]]]);
        swap(pos2[c[i][0]], pos2[c[i][1]]);
    }
    len = 1;
    f[0] = v2[1];
    for (int i = 2; i <= n; ++i)
    {
        int pos = lower_bound(f, f + len, v2[i]) - f;
        f[pos] = v2[i];
        len = max(len, pos + 1);
    }
    cout << len << endl;
}
