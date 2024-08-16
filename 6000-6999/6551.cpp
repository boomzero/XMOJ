#include <cstdio>
const int MAXN = 1000;
int primes[MAXN], isNotPrime[MAXN + 1], cnt;
inline void getPrimes() {
	isNotPrime[0] = isNotPrime[1] = true;
	for (int i = 2; i <= MAXN; i++) {
		if (!isNotPrime[i]) {
			primes[++cnt] = i;
		}
		for (int j = 1; j <= cnt && i * primes[j] <= MAXN; j++) {
			isNotPrime[i * primes[j]] = true;
			if (i % primes[j] == 0) break;
		}
	}
	// for (int i = 0; i < cnt; i++) printf("%d\n", primes[i]);
}
int main() {
	int n;
	scanf("%d", &n);	
	getPrimes();
	static long long f[MAXN + 1][MAXN + 1];
	f[0][0] = 1;
	for (int i = 1; i <= cnt; i++) {
		for (int k = 0; k <= n; k++) f[i][k] = f[i - 1][k];
		for (int p = primes[i]; p <= n; p *= primes[i]) {
			for (int k = p; k <= n; k++) {
				f[i][k] += f[i - 1][k - p];
			}
		}
		// for (int k = 0; k <= n; k++) printf("f[%d][%d] = %d\n", i, k, f[i][k]);
	}
	
	long long ans = 0;
	for (int i = 0; i <= n; i++) ans += f[cnt][i];
	printf("%lld\n", ans);
	return 0;
}
