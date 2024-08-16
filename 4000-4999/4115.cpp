#include <bits/stdc++.h>
using namespace std;
int n, k, b, dp[100010];
long long ans = 1e9;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//	freopen("light.in","r",stdin);
	//	freopen("light.out","w",stdout);
	memset(dp, 1, sizeof(dp));
	scanf("%d%d%d", &n, &k, &b);
	for (int i = 0; i < b; i++)
	{
		int x;
		scanf("%d", &x);
		dp[x] = 0;
	}
	if (n == k)
	{
		cout << b;
		return 0;
	}
	for (int i = 1; i <= n - k + 1; i++)
	{
		long long fix = 0;
		for (int j = 0; j < k; j++)
		{
			if (dp[i + j] == 0)
				fix += 1;
			//			if(fix>ans) break;
		}
		ans = min(ans, fix);
		//		cout<<i<<" "<<i+k<<" "<<ans<<endl;
	}
	printf("%lld", ans);
	return 0;
}
