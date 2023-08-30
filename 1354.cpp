#include <stdio.h>
#include <string.h>
struct node
{
	int l, r;
	int sum;
} a[400010];
void Bulid(int n, int l, int r)
{
	a[n].l = l;
	a[n].r = r;
	a[n].sum = 0;
	if (l == r)
		return;
	Bulid(2 * n, l, (l + r) / 2);
	Bulid(2 * n + 1, (l + r) / 2 + 1, r);
}
void Insert(int n, int v, int num)
{
	a[n].sum += num;
	if (a[n].l == a[n].r)
		return;
	if (v <= (a[n].l + a[n].r) / 2)
		Insert(n * 2, v, num);
	else
		Insert(n * 2 + 1, v, num);
}
void Change(int n, int v, int num)
{
	if (v == a[n].l && v == a[n].r)
	{
		a[n].sum += num;
		return;
	}
	else
		if (v <= (a[n].l + a[n].r) / 2)
		Change(n * 2, v, num);
	else
		Change(n * 2 + 1, v, num);
	a[n].sum = a[n * 2].sum + a[n * 2 + 1].sum;
}
int Sum(int n, int l, int r)
{
	if (l == a[n].l && r == a[n].r)
		return a[n].sum;
	if (r <= (a[n].l + a[n].r) / 2)
		return Sum(n * 2, l, r);
	else
		if (l > (a[n].l + a[n].r) / 2)
		return Sum(n * 2 + 1, l, r);
	else
		return Sum(n * 2, l, (a[n].l + a[n].r) / 2) + Sum(n * 2 + 1, (a[n].l + a[n].r) / 2 + 1, r);
}
int main()
{
	int i, j, n, m, Q, L, R;
	scanf("%d", &n);
	Bulid(1, 1, n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		Insert(1, i, m);
	}
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d %d %d", &Q, &L, &R);
		if (Q == 1)
		{
			Change(1, L, R);
		}
		else if (Q == 2)
		{
			printf("%d\n", Sum(1, L, R));
		}
	}
	return 0;
}
