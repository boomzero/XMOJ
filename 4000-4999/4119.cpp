#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n;
#define MAXN 100010
struct seq
{
	int l,r;
	seq(){l = r = -1;}
}s[MAXN >> 1];
bool cmp_l(seq a,seq b){return a.l < b.l;}
int c[MAXN];
int lowbit(int x){return x & (-x);}
void add(int p){for(int i = p;i <= n * 2;i += lowbit(i))++c[i];return;}
int query(int p){int res = 0;for(int i = p;i >= 1;i -= lowbit(i))res += c[i];return res;}
int main()
{
	scanf("%d",&n);
	int a;
	for(int i = 1;i <= n * 2;++i)
	{
		scanf("%d",&a);
		if(s[a].l == -1)s[a].l = i;
		else s[a].r = i;
	}
	sort(s + 1,s + 1 + n,cmp_l);
	int ans = 0;
	for(int i = 1;i <= n;++i)
	{
		add(s[i].r);
		ans += query(s[i].r - 1) - query(s[i].l);
	}
	cout << ans;
	return 0;
}
