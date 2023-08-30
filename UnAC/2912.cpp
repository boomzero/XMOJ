#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const unsigned int N = 105;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
unsigned int n, k, c[N], m[N];
bool Visited[N];
vector<unsigned int> to[N];
void AddEdge(unsigned int u, unsigned int v)
{
    to[u].push_back(v);
    to[v].push_back(u);
}
ll DFS(unsigned int x, unsigned short d)
{
    Visited[x] = true;
    ll Answer = c[x];
    if (d != k)
        for (auto i : to[x])
            if (!Visited[i])
                Answer += DFS(i, d + 1);
    Visited[x] = false;
    return Answer;
}
int main()
{
    freopen("near.in", "r", stdin);
    freopen("near.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (unsigned int i = 1; i < n; i++)
    {
        unsigned int x, y;
        scanf("%d%d", &x, &y);
        AddEdge(x, y);
    }
    for (unsigned int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (unsigned int i = 1; i <= n; i++)
        printf("%lld\n", DFS(i, 0));
    return 0;
}
