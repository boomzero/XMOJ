#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  freopen("matrix.in", "r", stdin);
  freopen("matrix.out", "w", stdout);
  int n, i, j, k, x, ans;
  scanf("%d%d%d", &n, &i, &j);
  x = min(i - 1, n - i);
  x = min(x, j - 1);
  x = min(x, n - j);
  ans = 4 * n * x - 4 * x * x;
  //
  if (i - x == 1)
    ans += j - x;
  else if (i + x == n)
    ans += 3 * n - 5 * x - 1 - j;
  else if (j - x == 1)
    ans += 4 * n - 7 * x - 2 - i;
  else
    ans += n - 3 * x + i - 1;
  printf("%d\n", ans);
  return 0;
}
