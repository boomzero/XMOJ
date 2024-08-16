#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 50;
typedef long long ll;
ll n;
ll f[MAXN][MAXN], root[MAXN][MAXN];

void print(ll l, ll r) {
	if (l > r)return;
	printf("%lld ", root[l][r]);
	if (l == r)return;
	print(l, root[l][r] - 1);
	print(root[l][r]+1,r);
}

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)scanf("%lld", &f[i][i]),f[i][i-1]=1, root[i][i] = i;
	for (int len = 1; len < n; ++len) {
		for (int i = 1; i + len <= n; ++i) {
			int j = i + len;
			f[i][j] = f[i + 1][j] + f[i][i];
			root[i][j] = i;
			for (int k = i + 1; k < j; ++k) {
				if (f[i][j] < f[i][k - 1] * f[k + 1][j] + f[k][k]) {
					f[i][j] = f[i][k - 1] * f[k + 1][j] + f[k][k];
					root[i][j] = k;
				}
			}
		}
	}
	cout<<f[1][n]<< endl;
	print(1, n);
	return 0;
}
