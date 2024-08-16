#include <cstdio>
#include <deque>
#define int long long

using namespace std;

int a[1000005], s[1000005], f[1000005], n, d, k;
deque<int> q;
deque<int> dq;

inline void defend()
{
	int p = -1;
	int t = q.size();
	while (t --)
	{
		if (f[q.front()] > p)
		q.push_back(q.front()), p = f[q.front()];
		q.pop_front();
	}
}

inline bool check(int g)
{
	q.clear(); dq.clear();
	for (int i = n; i >= 0; i --)
	{
		bool flag = 0;
		while (q.size() && a[q.back()] > a[i] + d + g) q.pop_back();
		while (dq.size() && a[dq.back()] >= a[i] + d - g)
		{
			if (a[dq.back()] <= a[i] + d + g && f[dq.back()] >= 0)
			q.push_front(dq.back());
			dq.pop_back();
			flag = 1;
		}
		if (flag) defend();
		f[i] = s[i];
		if (q.size()) f[i] += f[q.back()];
		if (a[i - 1] + d - g <= a[i]) q.push_front(i);
		else dq.push_front(i);
		defend();
	}
	return f[0] >= k;
}

signed main()
{
	freopen("jump.in","r",stdin);
		freopen("jump.out","w",stdout);
	scanf("%lld%lld%lld", &n, &d, &k);
	for (int i = 1; i <= n; i ++)
	scanf("%lld%lld", a + i, s + i);
	int l = 1, r, rl;
	if (a[n] > d) r = rl = a[n];
	else r = rl = d;
	int mid, ans = r;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	if (check(rl)) printf("%lld", ans);
	else puts("-1");
}
