#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1000005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
ll n, a[10], Answer, Distance[N];
bool Visited[N];
queue<ll> Queue;
void Dijkstra()
{
    fill(Distance, Distance + N, INF);
    Queue.push(0);
    Visited[0] = true;
    Distance[0] = 0;
    while (!Queue.empty())
    {
        ll u = Queue.front();
        Queue.pop();
        Visited[u] = 0;
        for (ll i = 2; i <= n; i++)
        {
            ll v = (u + a[i] % a[1]) % a[1];
            if (Distance[v] > Distance[u] + a[i])
            {
                Distance[v] = Distance[u] + a[i];
                if (!Visited[v])
                {
                    Visited[v] = 1;
                    Queue.push(v);
                }
            }
        }
    }
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    if (n == 2)
    {
        printf("%lld\n", a[1] * a[2] - a[1] - a[2]);
        return 0;
    }
    Dijkstra();
    Answer = -1;
    for (ll i = 1; i < a[1]; i++)
        Answer = max(Answer, Distance[i]);
    printf("%lld\n", Answer - a[1]);
    return 0;
}
