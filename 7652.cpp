#include <cstdio>
#include <iostream> 
using namespace std;
const int maxn = 1005;
int n, m, p[maxn], phi[maxn], tot;
bool mark[maxn];
long long ans;
long long C(long long x) { return x * (x-1) * (x-2) / 6; }
void sieve(int n) {
	phi[1] = 1;
	for(int i = 2; i <= n; ++i) {
		if(!mark[i]) p[++tot] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot and p[j]*i <= n; ++j) {
			mark[p[j]*i] = true;
			if(i % p[j]) phi[p[j]*i] = phi[i] * (p[j]-1);
			else { phi[p[j]*i] = phi[i] * p[j]; break; }
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	if(n > m) swap(n, m);
	sieve(n);
	for(int d = 2, x, y; d <= n; ++d)
		ans += (long long)phi[d]*(n-d+n%d+2)*(n/d)*(m-d+m%d+2)*(m/d)/2;
	ans = C((n+1)*(m+1)) - (m+1)*C(n+1) - (n+1)*C(m+1) - ans;
	printf("%lld", ans);
}
