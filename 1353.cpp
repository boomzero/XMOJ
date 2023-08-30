#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAXN = 100010 /*数字表示数字的最大值*/;

int n, q, val[MAXN << 2] /*结果存储*/, lazy[MAXN << 2], init_val[MAXN] /*init_val是最初的数值*/;

void push_up(int rt)
{

	val[rt] = val[rt * 2] + val[rt * 2 + 1]; // 求和
}

void push_down(int rt, int l, int r)
{

	if (lazy[rt] != -1)
	{

		lazy[rt * 2] = lazy[rt];

		lazy[rt * 2 + 1] = lazy[rt];

		val[rt * 2] = lazy[rt] * ((l + r) / 2 - l + 1); // val[rt*2]+=lazy[rt]*((l+r)/2-l+1);

		val[rt * 2 + 1] = lazy[rt] * (r - (l + r) / 2); // val[rt*2+1]+=lazy[rt]*（r-(l+r)/2);

		//		cout<<lazy[rt]<<" "<<l<<" "<<r<<endl;

		lazy[rt] = -1;
	}
}

void build(int rt, int l, int r)
{ /*l，r分别表示管理的左端点和右端点*/

	/*全局调用build(1,1,n)*/

	if (l == r)
		val[rt] = 1;

	else
	{

		int mid = (l + r) / 2;

		build(rt * 2, l, mid);

		build(rt * 2 + 1, mid + 1, r);

		push_up(rt);
	}

} // 构建

int query(int rt, int l, int r, int ql, int qr)
{

	if (ql > r || qr < l)
		return 0; // 求和返回0

	if (ql <= l && qr >= r)
		return val[rt];

	push_down(rt, l, r);

	int mid = (l + r) / 2;

	return query(rt * 2, l, mid, ql, qr) + query(rt * 2 + 1, mid + 1, r, ql, qr); // 求和

} // 调用求答案（自行更改return内容）

void update(int rt, int l, int r, int ul, int ur, int c)
{

	if (ul > r || ur < l)
		return;

	if (ul <= l && ur >= r)
	{

		val[rt] = c * (r - l + 1); // val[rt]+=add*(r-l+1)//求和

		lazy[rt] = c;

		return;
	}

	push_down(rt, l, r);

	int mid = (l + r) / 2;

	update(rt * 2, l, mid, ul, ur, c);

	update(rt * 2 + 1, mid + 1, r, ul, ur, c);

	push_up(rt);

} // 区间更新

int main()
{

	//	freopen("test.in","r",stdin);

	//	freopen("test.out","w",stdout);

	memset(lazy, -1, sizeof lazy);

	memset(init_val, 1, sizeof init_val);

	int ask;

	scanf("%d%d%d", &n, &q, &ask);

	build(1, 0, n);

	while (q--)
	{

		int a, b;

		scanf("%d%d", &a, &b);

		update(1, 0, n, a, b, 0);
	}

	while (ask--)
	{

		int a, b;

		scanf("%d%d", &a, &b);

		printf("%d\n", query(1, 0, n, a, b));
	}

	return 0;
}
