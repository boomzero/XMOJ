#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010, MAXB = 100010;
int n, b;
int f[MAXN], id1[MAXN], pre[MAXN], nxt[MAXN];
int s[MAXB], d[MAXB], id2[MAXB], ans[MAXB];
bool cmp1(int a, int b) { return f[a] < f[b]; }
bool cmp2(int a, int b) { return s[a] < s[b]; }
int main()
{
	freopen("mud.in", "r", stdin);
	freopen("mud.out", "w", stdout);
	scanf("%d%d", &n, &b);
	for (int i = 0; i < n; ++i)
		scanf("%d", &f[i]), id1[i] = i;
	for (int i = 0; i < b; ++i)
		scanf("%d%d", &s[i], &d[i]), id2[i] = i;
	sort(id1, id1 + n, cmp1);
	sort(id2, id2 + b, cmp2);
	for (int i = 0; i < n; ++i)
		nxt[i] = i + 1, pre[i] = i - 1;
	for (int i = b - 1, j = n - 1, ms = 1; i >= 0; --i)
	{
		int boot = id2[i];
		while (j >= 0 && f[id1[j]] > s[boot])
		{
			int cur = id1[j];
			nxt[pre[cur]] = nxt[cur];
			pre[nxt[cur]] = pre[cur];
			ms = max(ms, nxt[cur] - pre[cur]);
			j--;
		}
		ans[boot] = (ms <= d[boot]);
	}
	for (int i = 0; i < b; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
