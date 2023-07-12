#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100'0005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
int n, m, t, rxa, rxc, rya, ryc, rp;
struct EDGE
{
    int v, w;
};
struct NODE
{
    ll Distance;
    int u;
};
bool operator<(NODE First, NODE Second)
{
    return First.Distance > Second.Distance;
}
vector<EDGE> Edges[N];
bool Visited[N];
ll Distance[N];
void AddEdge(int u, int v, int w)
{
    Edges[u].push_back({v, w});
}
ll Dijkstra()
{
    priority_queue<NODE> Heap;
    Heap.push({0, 1});
    fill(Distance, Distance + N, INF);
    Distance[1] = 0;
    while (!Heap.empty())
    {
        ll u = Heap.top().u;
        Heap.pop();
        if (!Visited[u])
        {
            Visited[u] = true;
            if (u == n)
                return Distance[n];
            for (auto i : Edges[u])
            {
                auto [v, w] = i;
                if (!Visited[v] && Distance[v] > Distance[u] + w)
                {
                    Distance[v] = Distance[u] + w;
                    Heap.push({Distance[v], v});
                }
            }
        }
    }
    return Distance[n];
}
int main()
{
    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d%d%d", &t, &rxa, &rxc, &rya, &ryc, &rp);
    int x = 0, y = 0;
    for (int i = 0; i < t; i++)
    {
        x = (x * rxa + rxc) % rp;
        y = (y * rya + ryc) % rp;
        int a = min(x % n + 1, y % n + 1);
        int b = max(y % n + 1, y % n + 1);
        AddEdge(a, b, (10 << 8) - 100 * a);
    }
    for (int i = 0; i < m - t; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        AddEdge(x, y, z);
    }
    printf("%lld\n", Dijkstra());
    return 0;
}
