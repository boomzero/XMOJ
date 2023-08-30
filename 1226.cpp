#include <bits/stdc++.h>
using namespace std;
int ls[1000001];
int main()
{
	ios::sync_with_stdio(false);
	freopen("brick.in", "r", stdin);
	freopen("brick.out", "w", stdout);
	int N, K;
	cin >> N >> K;
	int m, n;
	for (int i = 0; i < K; i++)
	{
		cin >> m >> n;
		ls[m]++;
		ls[n + 1]--;
	}
	for (int i = 2; i < N + 1; i++)
	{
		ls[i] = ls[i] + ls[i - 1];
	}
	sort(ls + 1, ls + N);
	cout << ls[N / 2] << "\n";
	return 0;
}
