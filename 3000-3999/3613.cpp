#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
int N, C, d[40][40], c[510][510];
int mps[3][40];
int main()
{
    cin >> N >> C;
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < C; ++j)
            cin >> d[i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> c[i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            mps[(i + j) % 3][c[i][j]]++;
    int ans = INF;
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < C; ++j)
        {
            if (i == j)
                continue;
            for (int k = 0; k < C; ++k)
            {
                if (i == k || j == k)
                    continue;
                int num = 0;
                for (int x = 0; x < 3; ++x)
                {
                    for (int y = 0; y < C; ++y)
                    {
                        if (mps[x][y + 1] == 0)
                            continue;
                        int before = y;
                        int cnt = mps[x][y + 1];
                        int after;
                        if (x == 0)
                            after = i;
                        if (x == 1)
                            after = j;
                        if (x == 2)
                            after = k;
                        num += cnt * d[before][after];
                    }
                }
                if (num < ans)
                    ans = num;
            }
        }
    cout << ans << endl;
    return 0;
}
