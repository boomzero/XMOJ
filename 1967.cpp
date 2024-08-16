#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
long long prime[100005], number[100005], pok[5] = {0, 2, 7, 63};
long long cnt;
void get(){
	for (long long i = 2; i < 100005; ++ i){
		if (!vis[i])
			prime[++ cnt] = i;
		number[i] = cnt;
		for (long long j = 1; j <= cnt && prime[j] * i < 100005; ++ j){
			vis[prime[j] * i] = 1;
			if (!(i % prime[j])) break;
        }
    }
}
long long Quick_pow(long long k, long long c, long long p){
	long long ans = 1;
	while (c){
		if (c & 1)
			ans = (__int128)ans * k % p;
		c >>= 1;
		k = (__int128)k * k % p;
	}
	return ans;
}
bool millerrabin(long long n, long long m){
	long long k = n - 1;
  	while (k){
  		long long v = Quick_pow(m, k, n);
  		if (v != n - 1 && v != 1)
  			return 0;
  		if (k & 1 || v == n - 1)
  			return 1;
  		k >>= 1;
  	}
  	return 1;
}
bool check(long long n){
	if (n < 2) return 0;
	for (long long i = 1; i <= 3; ++ i){
		if (n == pok[i]) return 1;
		if (!millerrabin(n, pok[i])) return 0;
    }
    return 1;
}
long long find(long long n){
	if (n < 100005) return prime[number[n]];
	for (long long i = n;; -- i){
		if (check(i)) return i;
    }
    return -1;
}
int main(){
  	get();
 	long long n;
	scanf("%lld",&n);
  	printf("%lld\n", find(n - 1));
  	return 0;
}
