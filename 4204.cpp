#include <bits/stdc++.h>
using namespace std;
int n, x[110], give[110], ans, c[110]; // give表示如果给第i个人球它可以给多少人
bool cmp(int a, int b)
{
	if (a > b)
		return false;
	return true;
}
int main()
{
	//	freopen("football.in","r",stdin);
	//	freopen("football.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	sort(x, x + n, cmp);
	give[0] = 1, give[n - 1] = n - 2;
	for (int i = 1; i < n - 1; i++)
	{
		if (x[i] - x[i - 1] > x[i + 1] - x[i])
		{
			give[i] = i + 1;
		}
		else if (x[i] - x[i - 1] <= x[i + 1] - x[i])
		{
			give[i] = i - 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (give[j] == i)
				c[i]++;
		}
	}
	/*	cout<<endl<<endl;
		for(int i=0;i<n;i++){
			cout<<c[i]<<" "<<give[i]<<endl;
		}
		cout<<endl<<endl;*/
	for (int i = 0; i < n; i++)
	{
		if (c[i] == 0)
			ans++ /*,cout<<i<<" "*/;
	}
	//	cout<<endl<<endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//			if(i==j) continue;
			if (give[i] == j && give[j] == i && c[i] == c[j] && c[i] == 1)
				ans++ /*,cout<<i<<" "<<j<<endl*/;
		}
	}
	printf("%d", ans);
	return 0;
}
