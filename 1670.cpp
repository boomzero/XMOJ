#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <set>
#include <queue>
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, n, a) for (int i = n; i >= a; i--)
#define enter putchar('\n')

using namespace std;
typedef long long ll;
const int M = 10005;
const int INF = 1000000009;

int read()
{
   int ans = 0, op = 1;
   char ch = getchar();
   while (ch < '0' || ch > '9')
   {
      if (ch == '-')
         op = -1;
      ch = getchar();
   }
   while (ch >= '0' && ch <= '9')
   {
      ans *= 10;
      ans += ch - '0';
      ch = getchar();
   }
   return ans * op;
}

int b, c, r, row[11], col[11], blo[11], maxd;
char s[11];

int B(int x, int y)
{
   return ((x - 1) / 3 * 3 + (y - 1) / 3) + 1;
}

int h()
{
   return max(r, max(b, c));
}

int cal(int x)
{
   return (!x) ? -1 : 1;
}

void change(int i, int j)
{
   row[i] ^= 1, col[j] ^= 1, blo[B(i, j)] ^= 1;
   r += cal(row[i]), c += cal(col[j]), b += cal(blo[B(i, j)]);
}

void dfs(int x, int y, int d)
{
   if (d > maxd)
      return;
   if (x == 9 && y == 9)
   {
      rep(i, 1, 9) if (row[i] | col[i] | blo[i]) return;
      printf("%d\n", maxd), exit(0);
   }
   if (row[x] | col[y] | blo[B(x, y)])
   {
      change(x, y);
      if (d + 1 + h() <= maxd)
         (y == 9) ? dfs(x + 1, 1, d + 1) : dfs(x, y + 1, d + 1);
      change(x, y);
      if (d + h() <= maxd)
         (y == 9) ? dfs(x + 1, 1, d) : dfs(x, y + 1, d);
   }
   else
      (y == 9) ? dfs(x + 1, 1, d) : dfs(x, y + 1, d);
}

int main()
{
   freopen("bsudoku.in", "r", stdin);
   freopen("bsudoku.out", "w", stdout);
   rep(i, 1, 9)
   {
      scanf("%s", s + 1);
      rep(j, 1, 9) if (s[j] == '1') change(i, j);
   }
   for (maxd = 0;; maxd++)
      dfs(1, 1, 0);
   return 0;
}
