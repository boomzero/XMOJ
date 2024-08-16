#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int m, n, k, l, d;
struct node
{
	int pos;
	int num;
} r[N], c[N];
bool cmp1(node a, node b)
{
	return a.num > b.num;
}
bool cmp2(node a, node b)
{
	return a.pos < b.pos;
}
int main()
{
	cin >> m >> n >> k >> l >> d;
	int x1, y1;
	int x2, y2;
	for (int i = 0; i < d; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		int x = min(x1, x2);
		int y = min(y1, y2);
		if (x1 == x2)
		{
			c[y].pos = y;
			c[y].num++;
		}
		else
		{
			r[x].pos = x;
			r[x].num++;
		}
	}
	sort(r + 1, r + m, cmp1);
	sort(c + 1, c + n, cmp1);
	sort(r + 1, r + k + 1, cmp2);
	sort(c + 1, c + l + 1, cmp2);
	for (int i = 1; i <= k; i++)
	{
		cout << r[i].pos;
		if (i < k)
			cout << " ";
	}
	cout << endl;
	for (int i = 1; i <= l; i++)
	{
		cout << c[i].pos;
		if (i < l)
			cout << " ";
	}
	return 0;
}
