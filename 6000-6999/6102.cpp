#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bitset>
#define IT vector<Q>::iterator
using namespace std;
const int N = 150000;
struct Q
{
	int l, r, id;
} q[N];
unsigned short cnt[N];
int qans[N], ans[N], bl[N], col[N], tmp[N], n, m, sl[N], sr[N], s[N], len[N], S[N][26];
vector<Q> ql[N], qr[N];
pair<int, int> mvl[N], mvr[N];
char st[N];
int cmp(const Q &a, const Q &b)
{
	return bl[a.l] == bl[b.l] ? ((bl[a.l] & 1) ? a.r < b.r : a.r > b.r) : a.l < b.l;
}
int main()
{
#ifdef Local_Test
	freopen("market.in", "r", stdin);
	freopen("market.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	scanf("%s", st + 1);
	for (int i = 1; i <= n; i++)
		col[i] = st[i] - 97;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ (1 << col[i]), tmp[i] = s[i];
	sort(tmp, tmp + n + 1);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			int w = s[i] ^ (1 << j), pos = lower_bound(tmp, tmp + n + 1, w) - tmp;
			if (pos <= n && tmp[pos] == w)
				S[i][len[i]++] = pos;
		}
	}
	for (int i = 0; i <= n; i++)
		s[i] = lower_bound(tmp, tmp + n + 1, s[i]) - tmp;
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
	int blo = 314;
	if (!blo)
		blo = 1;
	for (int i = 1; i <= n; i++)
		bl[i] = (i - 1) / blo + 1;
	sort(q + 1, q + m + 1, cmp);
	int l = 1, r = 0;
	for (int i = 1; i <= m; i++)
	{
		if (r < q[i].r)
			qr[l - 1].push_back((Q){r, q[i].r, i}), mvr[i] = make_pair(r, q[i].r), r = q[i].r;
		if (l > q[i].l)
			ql[r].push_back((Q){l, q[i].l, i}), mvl[i] = make_pair(l, q[i].l), l = q[i].l;
		if (r > q[i].r)
			qr[l - 1].push_back((Q){r, q[i].r, i}), mvr[i] = make_pair(r, q[i].r), r = q[i].r;
		if (l < q[i].l)
			ql[r].push_back((Q){l, q[i].l, i}), mvl[i] = make_pair(l, q[i].l), l = q[i].l;
	}
	for (int i = 1; i <= n; i++)
	{
		cnt[s[i - 1]]++;
		for (int j = 0; j < len[i - 1]; j++)
			cnt[S[i - 1][j]]++;
		sr[i] = sr[i - 1] + cnt[s[i]];
		for (IT j = qr[i].begin(); j != qr[i].end(); j++)
		{
			int l = j->l, r = j->r, id = j->id, f = -1, t = 0;
			if (l > r)
				swap(l, r), f = 1;
			for (int k = l + 1; k <= r; k++)
				t += cnt[s[k]];
			qans[id] += f * t;
		}
	}
	cnt[s[0]]--;
	for (int j = 0; j < len[0]; j++)
		cnt[S[0][j]]--;
	cnt[s[n]]++;
	for (int j = 0; j < len[n]; j++)
		cnt[S[n][j]]++;
	for (int i = n; i >= 1; i--)
	{
		for (IT j = ql[i].begin(); j != ql[i].end(); j++)
		{
			int l = j->l, r = j->r, id = j->id, f = -1, t = 0;
			if (l > r)
				swap(l, r), f = 1;
			for (int k = l; k < r; k++)
				t += cnt[s[k - 1]];
			qans[id] += f * t;
		}
		cnt[s[i]]--;
		for (int j = 0; j < len[i]; j++)
			cnt[S[i][j]]--;
		sl[i] = cnt[s[i - 1]];
	}
	for (int i = 1; i <= n; i++)
		sl[i] += sl[i - 1];
	for (int i = 1; i <= m; i++)
	{
		qans[i] += qans[i - 1];
		qans[i] += sr[mvr[i].second] - sr[mvr[i].first];
		if (mvl[i].second)
			qans[i] += sl[mvl[i].second - 1] - sl[mvl[i].first - 1];
		ans[q[i].id] = qans[i];
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
}
