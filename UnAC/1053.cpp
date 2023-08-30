#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> g[205];
int dis[205] = {0};
struct node
{
    int d = 0, v = 0;
    vector<int> pt;
    bool operator<(const node &rhs) const
    {
        return d < rhs.d;
    }
    bool operator>(const node &rhs) const
    {
        return rhs < *this;
    }
    bool operator<=(const node &rhs) const
    {
        return !(rhs < *this);
    }
    bool operator>=(const node &rhs) const
    {
        return !(*this < rhs);
    }
    node(int d, int v, const vector<int> &pt) : d(d), v(v), pt(pt) {}
    node()
    {
        d = 0;
        v = 0;
        pt.resize(105);
        for (int i = 1; i <= n; ++i)
        {
            if (g[i].size() > 0)
                pt[i] = g[i][0];
        }
    }
};
int main()
{
    cin >> n >> a >> b;
    fill(dis, dis + 1 + n, numeric_limits<int>::max());
    for (int i = 1; i <= n; ++i)
    {
        int p;
        cin >> p;
        for (int j = 1; j <= p; ++j)
        {
            int v;
            cin >> v;
            g[i].push_back(v);
        }
    }
    dis[a] = 0;
    priority_queue<node, vector<node>, greater<node>> pq;
    node st;
    st.v = a;
    pq.emplace(st);
    while (!pq.empty())
    {
        int c = pq.top().v;
        node cn = pq.top();
        pq.pop();
        if (c == b)
            break;
        for (int i : g[c])
        {
            if (i == cn.pt[c])
            {
                if (dis[i] > dis[c])
                {
                    pq.emplace(dis[c], i, cn.pt);
                    dis[i] = dis[c];
                }
            }
            else
            {
                if (dis[i] > dis[c] + 1)
                {
                    vector<int> tpt = cn.pt;
                    tpt[c] = i;
                    pq.emplace(dis[c] + 1, i, tpt);
                    dis[i] = dis[c] + 1;
                }
            }
        }
    }
    if (dis[b] == numeric_limits<int>::max())
        cout << -1 << endl;
    else
        cout << dis[b] << endl;
    return 0;
}
