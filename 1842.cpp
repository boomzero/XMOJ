#include <bits/stdc++.h>
using namespace std;
const int maxn = 201000;
struct node
{
	long long l, r;
};
vector<node> a[26][26];
vector<node>::iterator iv;
long long n;
long long length[26];
char s[maxn];
long long ans = 0;
void init()
{
	long long i = 1, j, ml, mr, l, r;
	ml = s[1], l = 1;
	while (s[i] == s[i + 1])
		i++, l++;
	while (i < n)
	{
		j = i + 1;
		mr = s[j];
		r = 1;
		while (j < n && s[j] == s[j + 1])
			j++, r++;
		a[ml - 'a'][mr - 'a'].push_back((node){l, r});
		i = j;
		l = r;
		ml = mr;
	}
	return;
}
bool cmp(node x, node y)
{
	return x.l > y.l;
}
void calc(int x, int y)
{
	sort(a[x][y].begin(), a[x][y].end(), cmp);
	iv = a[x][y].begin();
	long long maxx = (*iv).l, maxy = (*iv).r;
	ans += maxx * maxy, iv++;
	for (; iv != a[x][y].end(); iv++)
	{
		if (maxy < (*iv).r)
		{
			ans += (*iv).l * ((*iv).r - maxy);
			maxy = (*iv).r;
		}
	}
}
int main()
{
	memset(length, 0, sizeof(length));
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (long long i = 1; i <= n;)
	{
		long long j = i;
		while (j < n && s[j] == s[j + 1])
			j++;
		length[s[i] - 'a'] = max(length[s[i] - 'a'], j - i + 1);
		i = j + 1;
	}
	for (int i = 0; i < 26; i++)
		ans += length[i];
	init();
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			if (a[i][j].size() > 0)
				calc(i, j);
	printf("%lld", ans);
	return 0;
}
