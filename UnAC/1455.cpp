#include <bits/stdc++.h>
using namespace std;
int fa[50001], rootId[50001];
int find(int t)
{
    if (fa[t] == t)
        return t;
    return fa[t] = find(fa[t]);
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        fa[x] = y;
    }
}
int assignMap[50001];
int main()
{
    int n;
    cin >> n;
    int assignId = 1;
    for (int i = 1; i <= 50000; ++i)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        int a, b, x = -1, y = -1;
        cin >> a >> b;
        for (int j = 1; j <= assignId; ++j)
        {
            if (assignMap[j] == a)
            {
                x = j;
            }
            else if (assignMap[j] == b)
            {
                y = j;
            }
        }
        if (x == -1)
        {
            x = assignId;
            assignMap[x] = a;
            assignId++;
        }
        if (y == -1)
        {
            y = assignId;
            assignMap[y] = b;
            assignId++;
        }
        merge(x, y);
    }
    for (int i = 1; i <= 50000; ++i)
    {
        rootId[find(i)]++;
    }
    int max = 0;
    for (int i = 1; i <= 50000; ++i)
    {
        if (rootId[i] > max)
        {
            max = rootId[i];
        }
    }
    cout << max << endl;
    return 0;
}
