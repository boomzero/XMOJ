#include <bits/stdc++.h>
using namespace std;
int n, a[100010], sum[100010], m[100010], maxsum;
int main()
{
	cin >> n;
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
		m[i] = min(m[i - 1], sum[i - 1]);
	}
	for (int j = 1; j <= n; j++)
	{
		maxsum = max(maxsum, sum[j] - m[j]);
	}
	for (int i = 1; i <= n; i++)
	{
		maxsum = max(maxsum, a[i]);
	}
	cout << maxsum;
}
