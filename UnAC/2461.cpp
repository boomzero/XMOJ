#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[30] = {false};
int stackSize = 0, a[30];
void dfs(int c)
{
    stackSize++;
    vis[c] = true;
    a[stackSize] = c;
    if (stackSize == n)
    {
        bool first = true;
        for (int i = 1; i <= stackSize; ++i)
        {
            if (!first)
                putchar(' ');
            first = false;
            printf("%d", a[i]);
        }
        putchar('\n');
        vis[c] = false;
        stackSize--;
        return;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (stackSize + 1 == i)
            continue;
        if (!vis[i])
        {
            dfs(i);
        }
    }
    vis[c] = false;
    stackSize--;
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        dfs(i);
    }
    return 0;
}
