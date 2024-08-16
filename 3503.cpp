#include<iostream>
using namespace std;
typedef long long ll;
inline ll rd() {
	ll x = 0;
	char c = getchar();
	bool f = false;
	while (!isdigit(c)) {
		if (c == '-') f = true;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -x : x;
}
 
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
int n, m, k;
int dp[200][200][23][23];
int mode = 12345678;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	dp[0][0][0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for(int x=0;x<=k;x++)
				for (int y = 0; y <= k; y++) {
					if (dp[i][j][x][y]) {
						int tp = dp[i][j][x][y];
						(dp[i + 1][j][x + 1][max(y - 1, 0)] += tp) %= mode;
						(dp[i][j + 1][max(x - 1, 0)][y + 1] += tp) %= mode;
					}
				}
		}
	}
	ll res = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			res = (res + dp[n][m][i][j]) % mode;
		}
	}
	cout<<(ll)res;
	return 0;
}
