#include <cstdio>
int a[1 << 22];
int main() {
	int n, k, x, y;
	long long i, A, B;
	int sum = 0;
	scanf ("%d%d", &n, &k);
	while (k --) {
		scanf("%d%d%lld%lld", &x, &y, &A, &B);
		
		for (i = 1; i <= y; i++) {
			a[(A * i + B) % n] += x;
		}
	}
	for (i = 0; i < n; i++) {
		sum += a[i];
		if (sum > 0) sum --;
	}
	for (i = 0; i < n; i++) {
		sum += a[i];
		if (sum > 0) sum --;
		else {
			printf ("%lld\n", i);
			break;
		}
	}
	return 0;
}
