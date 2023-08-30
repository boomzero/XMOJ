#include <bits/stdc++.h>

using namespace std;

int f[30][30];

int dfs(int i, int j)

{

  if (f[i][j])

    return f[i][j];

  if (i == 0)

    return f[i][j] = 1;

  if (j == 0)

    return f[i][j] = dfs(i - 1, j + 1);

  return f[i][j] = dfs(i - 1, j + 1) + dfs(i, j - 1);
}

int main()
{

  int n;

  cin >> n;

  cout << dfs(n, 0);

  return 0;
}
