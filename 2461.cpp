#include <bits/stdc++.h>

using namespace std;

int n, a[20], vis[20];

void print()

{

    for (int i = 1; i <= n; ++i)

        printf("%d ", a[i]);

    printf("\n");
}

void dfs(int dep)
{

    if (dep == n + 1)
    {
        print();
        return;
    }

    for (int i = 1; i <= n; ++i)

        if (i != dep && !vis[i])
        {

            a[dep] = i;

            vis[i] = 1;

            dfs(dep + 1);

            vis[i] = 0;
        }
}

int main()
{

    scanf("%d", &n);

    dfs(1);

    return 0;
}
