#include <bits/stdc++.h>

using namespace std;

#define maxn 200007

int arr[maxn];

struct SegTreeNode
{

	int mx;

} SegTree[maxn << 2];

inline void PushUp(int rt)
{

	SegTree[rt].mx = max(SegTree[rt * 2].mx, SegTree[rt * 2 + 1].mx);
}

inline void build(int l, int r, int rt)
{

	if (l == r)
	{

		SegTree[rt].mx = arr[l];

		return;
	}

	int m = (l + r) / 2;

	build(l, m, rt * 2);

	build(m + 1, r, rt * 2 + 1);

	PushUp(rt);
}

inline void Update(int L, int C, int l, int r, int rt)
{

	if (l == r)
	{

		SegTree[rt].mx = C;

		return;
	}

	int m = (l + r) / 2;

	if (L <= m)
	{

		Update(L, C, l, m, rt * 2);
	}
	else
	{

		Update(L, C, m + 1, r, rt * 2 + 1);
	}

	PushUp(rt);
}

inline int Query(int L, int R, int l, int r, int rt)
{

	if (l >= L && r <= R)
	{

		return SegTree[rt].mx;
	}

	if (l > R || r < L)
	{

		return 0;
	}

	int ans = 0;

	int m = (l + r) / 2;

	if (L <= m)
	{

		ans = max(ans, Query(L, R, l, m, rt * 2));
	}

	if (R > m)
	{

		ans = max(ans, Query(L, R, m + 1, r, rt * 2 + 1));
	}

	return ans;
}

int main()
{

	ios::sync_with_stdio(false);

	int n, m;

	char c;

	int a, b;

	int t;

	cin >> t;

	while (t--)
	{

		cin >> n >> m;

		for (int i = 1; i <= n; i++)
		{

			cin >> arr[i];
		}

		build(1, n, 1);

		for (int i = 0; i < m; i++)
		{

			cin >> c >> a >> b;

			if (c == 'U')
			{

				Update(a, b, 1, n, 1);
			}

			else
			{

				cout << Query(a, b, 1, n, 1) << endl;
			}
		}

		memset(SegTree, 0, sizeof SegTree);
	}

	return 0;
}
