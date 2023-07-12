#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int INF = 0x3FFF'FFFF;
int n, x[N], y[N], m, Count[N * N], Head[N], EdgeCount, Distance[N], Answer, MaxLength;
bool Visited[N];
struct EDGE
{
    int v, w, Next;
} Edges[N * N];
void AddEdge(int u, int v, int w)
{
    EdgeCount++;
    Edges[EdgeCount].v = v;
    Edges[EdgeCount].w = w;
    Edges[EdgeCount].Next = Head[u];
    Head[u] = EdgeCount;
}
void AddTwoWayEdge(int u, int v, int w)
{
    AddEdge(u, v, w);
    AddEdge(v, u, w);
}
int Kruskal()
{
    fill(Distance + 1, Distance + n + 1, INF);
    Distance[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int Min = INF, MinIndex = 0;
        for (int j = 1; j <= n; j++)
            if (!Visited[j] && Distance[j] < Min)
            {
                Min = Distance[j];
                MinIndex = j;
            }
        if (MinIndex == 0)
            break;
        Visited[MinIndex] = true;
        for (int j = Head[MinIndex]; j; j = Edges[j].Next)
        {
            int v = Edges[j].v;
            if (!Visited[v] && Distance[v] > Edges[j].w)
                Distance[v] = Edges[j].w;
        }
    }
    return *max_element(Distance + 1, Distance + n + 1);
}
int main()
{
    freopen("kongfu.in", "r", stdin);
    freopen("kongfu.out", "w", stdout);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int p;
        scanf("%d", &p);
        Count[p * p]++;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                AddTwoWayEdge(i, j,
                              (x[i] - x[j]) * (x[i] - x[j]) +
                                  (y[i] - y[j]) * (y[i] - y[j]));
    MaxLength = Kruskal();
    for (int i = MaxLength; i < N * N; i++)
        Answer += Count[i];
    printf("%d\n", Answer);
    return 0;
}
