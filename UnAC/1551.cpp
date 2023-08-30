#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int n, win[N][N];
bool f[N * 2][N * 2];
set<int> Answer;
bool Win(int First, int Second)
{
    First = (First - 1) % n + 1;
    Second = (Second - 1) % n + 1;
    if (First > Second)
        swap(First, Second);
    return win[First][Second];
}
int main()
{
    // freopen("fight.in", "r", stdin);
    // freopen("fight.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= n - i; j++)
            scanf("%d", &win[i][i + j]);
    for (int i = 1; i <= n * 2; i++)
        f[i][i + 1] = true;
    for (int Length = 2; Length <= n; Length++)
        for (int i = 1; i <= n * 2; i++)
        {
            int j = i + Length;
            for (int k = i + 1; k < j; k++)
                if (f[i][k] && f[k][j] && (Win(i, k) || Win(k, j)))
                {
                    f[i][j] = true;
                    break;
                }
        }
    for (int i = 1; i <= n; i++)
        if (f[i][i + n])
            Answer.insert(i);
    printf("%d\n", Answer.size());
    for (auto i : Answer)
        printf("%d\n", i);
    return 0;
}
