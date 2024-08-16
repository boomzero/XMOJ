#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
const ll N = 80005;
const ll M = 800005;
ll Head[N], Distance[N], To[M], Weight[M], Next[M];
ll n, Start, End, EdgeCount = 1, Answer;
void AddEdge(ll u, ll v, ll w)
{
    EdgeCount++;
    To[EdgeCount] = v;
    Weight[EdgeCount] = w;
    Next[EdgeCount] = Head[u];
    Head[u] = EdgeCount;
}
void AddTwoEdges(ll u, ll v, ll w)
{
    AddEdge(u, v, w);
    AddEdge(v, u, 0);
}
bool BFS()
{
    memset(Distance, 0, sizeof(Distance));
    queue<ll> Queue;
    Queue.push(Start);
    Distance[Start] = 1;
    while (Queue.size())
    {
        ll u = Queue.front();
        Queue.pop();
        for (ll i = Head[u]; i; i = Next[i])
        {
            ll v = To[i];
            if (Weight[i] && !Distance[v])
            {
                Queue.push(v);
                Distance[v] = Distance[u] + 1;
                if (v == End)
                    return 1;
            }
        }
    }
    return 0;
}
ll Dinic(ll u, ll Flow)
{
    if (u == End)
        return Flow;
    ll Rest = Flow;
    for (ll i = Head[u]; i && Rest; i = Next[i])
    {
        ll v = To[i];
        if (Weight[i] && Distance[v] == Distance[u] + 1)
        {
            ll k = Dinic(v, min(Rest, Weight[i]));
            if (!k)
                Distance[v] = 0;
            Weight[i] -= k;
            Weight[i ^ 1] += k;
            Rest -= k;
        }
    }
    return Flow - Rest;
}
int main()
{
    ll T;
    scanf("%lld", &T);
    while (T-- > 0)
    {
        Answer = 0;
        memset(Weight, 0, sizeof(Weight));
        memset(To, 0, sizeof(To));
        memset(Head, 0, sizeof(Head));
        memset(Next, 0, sizeof(Next));
        EdgeCount = 1;
        scanf("%lld", &n);
        Start = 2 * n + 1;
        End = 2 * n + 2;
        for (ll i = 1; i <= n; ++i)
        {
            AddTwoEdges(Start, i, 1);
            AddTwoEdges(i + n, End, 1);
        }
        for (ll i = 1; i <= n; ++i)
            for (ll j = 1; j <= n; j++)
            {
                ll x;
                scanf("%lld", &x);
                if (x == 1)
                    AddTwoEdges(i, j + n, 1);
            }
        ll Flow = 0;
        while (BFS())
            do
            {
                Flow = Dinic(Start, INF);
                Answer += Flow;
            } while (Flow);
        if (Answer >= n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
