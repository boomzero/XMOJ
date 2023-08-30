#include <iostream>

#include <cstdio>

#include <cstring>

#include <algorithm>

using namespace std;

int n, q, sum[100005 << 2], x1, x2, y1, y2;

namespace IO
{

	void read(int &x)
	{

		char ch;
		x = 0;

		while (ch = getchar(), ch < '0' || ch > '9')
			;
		x = ch - 48;

		while (ch = getchar(), ch >= '0' && ch <= '9')

			x = 10 * x + ch - 48;
	}

}

using namespace IO;

namespace Segtree
{

	void build(int rt, int l, int r)
	{

		if (l == r)
		{

			read(sum[rt]);

			return;
		}

		int mid = l + r >> 1;

		build(rt << 1, l, mid);

		//	cout<<"build complete1"<<endl;

		build(rt << 1 | 1, mid + 1, r);

		//	cout<<"build complete2"<<endl;

		sum[rt] = min(sum[rt << 1], sum[rt << 1 | 1]);
	}

	int query(int rt, int l, int r, int lq, int rq)
	{

		if (lq <= l && r <= rq)

			return sum[rt];

		int mid = l + r >> 1;

		if (lq > mid)

			return query(rt << 1 | 1, mid + 1, r, lq, rq);

		else if (rq <= mid)

			return query(rt << 1, l, mid, lq, rq);

		else

			return min(query(rt << 1, l, mid, lq, rq), query(rt << 1 | 1, mid + 1, r, lq, rq));
	}

}

using namespace Segtree;

int main()
{

	read(n);

	build(1, 1, n);

	read(q);

	while (q--)
	{

		read(x1);

		read(y1);

		read(x2);

		read(y2);

		int num = query(1, 1, n, min(x1, x2), max(x1, x2));

		if (y1 <= num && y2 <= num)

			printf("%d\n", abs(x2 - x1) + abs(y2 - y1));

		else

			printf("%d\n", abs(y1 - num) + abs(y2 - num) + abs(x2 - x1));
	}

	return 0;
}
