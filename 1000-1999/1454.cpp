#include <bits/stdc++.h>
using namespace std;
int fa[1000010], num = 0;
int a[1000010], b[1000010];
map<int, int> room;
int find(int t)
{
	if (fa[t] == t)
		return t;
	return fa[t] = find(fa[t]);
}
void merge(int x, int y)
{
	//	printf("<%d,%d>",x,y);
	x = find(x);
	y = find(y);
	if (x != y)
	{
		fa[x] = y;
		num--;
		//		printf("%d->",num);
	}
	if (x == y)
	{
		//		printf("wrong:%d,%d",x,y);
		printf("No"), exit(0);
	}
}
int main()
{
	int n = 0;
	for (int i = 1; i <= 100010; i++)
		fa[i] = i;
	int id = 0;
	while (true)
	{
		scanf("%d%d", &a[id], &b[id]);
		id++;
		if (a[id - 1] == 0 && b[id - 1] == 0)
			break;
		n = max(n, max(a[id - 1], b[id - 1]));
		room[a[id - 1]] = 1;
		room[b[id - 1]] = 1;
		num = room.size();
	}
	id -= 1;
	for (int i = 0; i < id; i++)
	{
		merge(a[i], b[i]);
	}
	//	printf("%d",num);
	if (num != 1)
		printf("No"), exit(0);
	printf("Yes");
	return 0;
}
