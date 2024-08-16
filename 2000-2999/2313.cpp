#include <bits/stdc++.h>
using namespace std;
int a[1000010], qmax[1000010], h1 = 1, t1 = 0, qmin[1000010], h2 = 1, t2 = 0, pos = 1, n, m, c;
bool b = 0;
int main()
{
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
  {
    while (i - qmax[h1] >= m && h1 <= t1)
      h1++;
    while (i - qmin[h2] >= m && h2 <= t2)
      h2++;
    while (a[qmax[t1]] < a[i] && h1 <= t1)
      t1--;
    while (a[qmin[t2]] > a[i] && h2 <= t2)
      t2--;
    qmax[++t1] = i;
    qmin[++t2] = i;
    if (i >= m && a[qmax[h1]] - a[qmin[h2]] <= c)
      printf("%d\n", i - m + 1), b = 1;
  }
  if (!b)
    printf("NONE");
  return 0;
}
