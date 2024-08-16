#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100001
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
int t, s, n, ans, mx = 1;
int val[N], f[N][101];
struct ski111{
	int m, l, a;
}q[N];
struct ski233{
	int c, d;
}p[N];
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
	for(; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}
inline bool cmp(ski233 x, ski233 y){
	return x.c < y.c;
}
int main(){
	int i, j;
	t = read();
	s = read();
	n = read();
	for(i = 1; i <= s; i++)
	{
		q[i].m = read();
		q[i].l = read();
		q[i].a = read();
	}
	for(i = 1; i <= n; i++)
	{
		p[i].c = read();
		p[i].d = read();
	}
	std::sort(p + 1, p + n + 1, cmp);
	j = 1;
	val[0] = 1e9;
	for(i = 1; i <= 100; i++)
	{
		val[i] = val[i - 1];
		for(; i == p[j].c && j <= n; j++)
			val[i] = min(val[i], p[j].d);
	}
	memset(f, -1, sizeof(f));
	f[0][1] = 0;
	for(i = 0; i <= t; i++){
		mx = -1;
		for(j = 1; j <= 100; j++){
			f[i + 1][j] = max(f[i + 1][j], f[i][j]);
			if(f[i][j] != -1 && val[j] != 1e9){
				mx = max(mx, f[i][j]);
				f[i + val[j]][j] = max(f[i + val[j]][j], f[i][j] + 1);
			}
		}
		for(j = 1; j <= s; j++)
			if(mx != -1 && i >= q[j].m)
				f[i + q[j].l][q[j].a] = max(f[i + q[j].l][q[j].a], mx);
	}
	for(i = 1; i <= 100; i++)
		ans=max(ans, f[t][i]);
	printf("%d", ans);
	return 0;
}
