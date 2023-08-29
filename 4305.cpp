#include <bits/stdc++.h>

using namespace std;
int diff[1005][1005];
int n, k, mx = 0, my = 0;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int mk = 0;
    // cin >> n >> k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        int x1, x2, y1, y2;
        //        cin >> x2 >> y1 >> x1 >> y2;
        //        cin >> x1 >> y1 >> x2 >> y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1++, y1++, x2++, y2++;
        mx = max(mx, max(x1, x2));
        my = max(my, max(y1, y2));
        ++diff[x1][y1];
        --diff[x1][y2];
        --diff[x2][y1];
        ++diff[x2][y2];
    }
    int ans = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= 1000; ++j)
        {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            if (diff[i][j] == k)
                ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
