#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAXN = 200010 /*数字表示数字的最大值*/;

int n, val[MAXN << 2] /*结果存储*/, lazy[MAXN << 2], init_val[MAXN] /*init_val是最初的数值*/;

void push_up(int rt)
{

	//	val[rt]=max(val[rt*2],val[rt*2+1]);//这段内容需要做什么就改为什么

	val[rt] = val[rt * 2] + val[rt * 2 + 1]; // 求和
}

// void push_down(int rt){

void push_down(int rt, int l, int r)
{

	if (lazy[rt] != 0)
	{

		lazy[rt * 2] += lazy[rt];

		lazy[rt * 2 + 1] += lazy[rt];

		//	val[rt*2]+=lazy[rt];

		val[rt * 2] += lazy[rt] * ((l + r) / 2 - l + 1);

		//	val[rt*2+1]+=lazy[rt];

		val[rt * 2 + 1] += lazy[rt] * (r - (l + r) / 2);

		lazy[rt] = 0;
	}
}

void build(int rt, int l, int r)
{ /*l，r分别表示管理的左端点和右端点*/

	/*全局调用build(1,1,n)*/

	if (l == r)
		val[rt] = init_val[l];

	else
	{

		int mid = (l + r) / 2;

		build(rt * 2, l, mid);

		build(rt * 2 + 1, mid + 1, r);

		push_up(rt);
	}

} // 构建

void update_one(int rt, int l, int r, int idx, int add)
{

	if (l == r)
	{

		val[rt] += add;

		return;
	}

	int mid = (l + r) / 2;

	if (idx <= mid)

		update_one(rt * 2, l, mid, idx, add);

	else

		update_one(rt * 2 + 1, mid + 1, r, idx, add);

	push_up(rt);

} // 单点更新

int query(int rt, int l, int r, int ql, int qr)
{

	if (ql > r || qr < l)
		return 0; // 求和返回0

	if (ql <= l && qr >= r)
		return val[rt];

	push_down(rt, l, r);

	int mid = (l + r) / 2;

	//	return max(query(rt*2,l,mid,ql,qr),query(rt*2+1,mid+1,r,ql,qr));

	return query(rt * 2, l, mid, ql, qr) + query(rt * 2 + 1, mid + 1, r, ql, qr); // 求和

} // 调用求答案（自行更改return内容）

void update(int rt, int l, int r, int ul, int ur, int add)
{

	if (ul > r || ur < l)
		return;

	if (ul <= l && ur >= r)
	{

		//	val[rt]+=add;

		val[rt] += add * (r - l + 1); // 求和

		lazy[rt] += add;

		return;
	}

	//	push_down(rt);

	push_down(rt, l, r);

	int mid = (l + r) / 2;

	update(rt * 2, l, mid, ul, ur, add);

	update(rt * 2 + 1, mid + 1, r, ul, ur, add);

	push_up(rt);

} // 区间更新

int main()
{

	ios::sync_with_stdio(false);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{

		scanf("%d", &init_val[i]);
	}

	build(1, 1, n);

	int m;

	scanf("%d", &m);

	while (m--)
	{

		int str;

		scanf("%d", &str);

		if (str == 1)
		{

			int x, a, b;

			scanf("%d%d%d", &a, &b, &x);

			update(1, 1, n, a, b, x);
		}

		else
		{

			int a, b;

			scanf("%d%d", &a, &b);

			printf("%d\n", query(1, 1, n, a, b));
		}
	}
}
