#include <bits/stdc++.h>
using namespace std;
struct node
{
	int v, next;
} edge[200010], edge1[200010];
int head[200010], head1[200010], cnt, cnt1;
int n, m, s, t;
int dis[200010], dis1[200010], vis[200010], vis1[200010], bj[200010];
struct cmp
{
	bool operator()(int a, int b)
	{
		return dis[a] > dis[b];
	}
};
struct cmp1
{
	bool operator()(int a, int b)
	{
		return dis1[a] > dis1[b];
	}
};
priority_queue<int, vector<int>, cmp> q;
priority_queue<int, vector<int>, cmp1> q1;
void addedge(int u, int v)
{
	edge[++cnt].v = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}
void addedge1(int u, int v)
{
	edge1[++cnt1].v = v;
	edge1[cnt1].next = head1[u];
	head1[u] = cnt1;
}
void spfa1()
{
	memset(dis1, 0x3f, sizeof(dis1));
	q1.push(t);
	dis1[t] = 0;
	vis1[t] = 1;
	while (!q1.empty())
	{
		int u = q1.top();
		q1.pop();
		vis[u] = 0;
		for (int i = head1[u]; i; i = edge1[i].next)
		{
			int v = edge1[i].v;
			if (dis1[v] > dis1[u] + 1)
			{
				dis1[v] = dis1[u] + 1;
				if (!vis1[v])
				{
					q1.push(v);
					vis1[v] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (dis1[i] == 1061109567)
		{
			bj[i] = 1;
			for (int j = head1[i]; j; j = edge1[j].next)
				if (edge1[j].v != s)
					bj[edge1[j].v] = 1;
		}
}
void spfa()
{
	memset(dis, 0x3f, sizeof(dis));
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!q.empty())
	{
		int u = q.top();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].v;
			if (bj[v] == 1)
				continue;
			if (dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				if (!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}
int main()
{
	//	freopen("road.in","r",stdin);
	//	freopen("road.out","w",stdout);
	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		addedge(a, b);
		addedge1(b, a);
	}
	scanf("%d%d", &s, &t);
	spfa1();
	if (bj[s] == 1)
		cout << "-1";
	else
	{
		spfa();
		cout << dis[t];
	}
	return 0;
}
