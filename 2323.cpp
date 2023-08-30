#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

int t;

int n;

int h[maxn];

char imp[10];

void up(int k)
{ /*插入k*/

	while (k > 1)
	{

		int i = k / 2;

		if (h[k] < h[i])
		{

			swap(h[k], h[i]);

			k = i;
		}

		else
			break;
	}

} /*在堆中插入一个元素x*/

void down(int k)
{ /*删除第k个节点*/

	while (k + k <= n)
	{

		int i = k + k;

		if (i + 1 <= n && h[i + 1] < h[i])
		{

			i++;
		}

		if (h[i] < h[k])
		{

			swap(h[i], h[k]);

			k = i;
		}

		else
			break;
	}

} /*在堆中删除根节点的元素（找最小值/删除最小值）*/

void add(int x)
{

	n++;

	h[n] = x;

	up(n);

} // 添加一个值为x的元素

void del(int pos)
{

	swap(h[pos], h[n]);

	n--;

	up(pos);

	down(pos);

} /*删除下标为pos的元素*/

int main()
{

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{

		scanf("%s", imp);

		if (imp[0] == 'a')
		{

			int x;

			scanf("%d", &x);

			add(x);
		}

		else if (imp[0] == 'q')
		{

			printf("%d\n", h[1]);

			del(1);
		}
	}

	return 0;
}
