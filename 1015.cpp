#include <bits/stdc++.h>
using namespace std;
int vis[1100000];
int dis[1100000];
struct A
{
    int s, c;
};
queue<A> que;
void move(int, int);
int main()
{
    int v = 0, s2;
    for (int i = 0, x; i < 20; ++i)
    {
        cin >> x;
        v |= x << i;
    }
    vis[v] = true;
    que.push((A){v, 0});
    while (!que.empty())
    {
        A a = que.front();
        que.pop();
        if (a.s == 0)
        {
            cout << a.c;
            break;
        }
        move(a.s ^ 3, a.c + 1);
        move(a.s ^ (3 << 18), a.c + 1);
        for (int x = 1, y = 7; x <= 18; ++x, y <<= 1)
            move(a.s ^ y, a.c + 1);
    }
    return 0;
}
void move(int s, int c)
{
    if (vis[s])
        return;
    vis[s] = true;
    que.push((A){s, c});
}
