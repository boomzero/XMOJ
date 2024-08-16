#include <bits/stdc++.h>
using namespace std;
int n, m, r;
long long dp[1010][1010]; // 第i个项目选项目j后前i个最大恢复体力值
long long dptime[1010][1010]; // 第i个项目选j后时间
struct Exercise
{
	int s, e, p;
} a[1010];
namespace IO
{
	template <typename T>
	void read(T &a)
	{
		a = 0;
		int f = 1;
		char ch = getchar();
		while (ch < '0' || ch > '9')
		{
			if (ch == '-')
				f = -1;
			ch = getchar();
		}
		do
		{
			a = a * 10 + ch - '0';
			ch = getchar();
		} while ('0' <= ch && ch <= '9');
		a *= f;
	}
	template <typename T>
	void write(T x)
	{
		if (!x)
			putchar('0');
		char f[200];
		int tmp = x > 0 ? x : -x;
		if (x < 0)
			putchar('-');
		int cnt = 0;
		while (tmp > 0)
		{
			f[cnt++] = tmp % 10 + '0';
			tmp /= 10;
		}
		while (cnt > 0)
			putchar(f[--cnt]);
	}
}
using namespace IO;
bool cmp(Exercise &a, Exercise &b)
{
	if (a.s < b.s)
		return true;
	if (a.s == b.s && a.e > b.e)
		return true;
	return false;
}
int main()
{
	freopen("gym.in", "r", stdin);
	freopen("gym.out", "w", stdout);
	read(n), read(m), read(r);
	for (int i = 1; i <= m; i++)
		read(a[i].s), read(a[i].e), read(a[i].p);
	sort(a + 1, a + m + 1, cmp);
	//	for(int i=1;i<=m;i++) write(a[i].s),cout<<" ",write(a[i].e),cout<<" ",write(a[i].p),cout<<endl;
	memset(dp, 0, sizeof dp);
	memset(dptime[0], -0x3f3f3f3f, sizeof dp[0]);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{ // if(time is okay) dp[i][j]=max(dp[i-1])+p[j]
			int lastt = 0;
			int maxdp = 0;
			for (int k = 1; k <= m; k++)
			{
				if (a[j].s >= a[k].e + r)
				{
					if (dp[i - 1][k] >= maxdp)
					{
						if (lastt > dp[i - 1][k] && dp[i - 1][k] == maxdp)
						{
							maxdp = dp[i - 1][k];
							lastt = dptime[i - 1][k];
							continue;
						}
						maxdp = dp[i - 1][k];
						lastt = dptime[i - 1][k];
					}
				} // max dp[i-1]
			}
			dp[i][j] = maxdp + a[j].p;
			dptime[i][j] = a[j].e;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= m; i++)
	{
		ans = max(ans, dp[m][i]);
	}
	printf("%lld", ans);
	return 0;
}
