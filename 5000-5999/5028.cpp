#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int q,d,l,n;vector<int> rt;
	scanf("%lld%lld%lld",&q,&d,&l);
	while (q--) {
		scanf("%lld",&n),rt.clear();
		rt.push_back(n);
		while (n<=0) {
			if (-n>l) {
				if (n%2==0) n/=2;
				else n=3*n+1;
			}else n+=d;
			rt.push_back(n);
		}
		while (n!=1) {
			if (n%2==0) n/=2;
			else n=3*n+1;
			rt.push_back(n);
		}
		reverse(rt.begin(),rt.end());
		printf("%lld ",rt.size()-1);
		for (int i:rt) printf("%lld ",i);
		putchar('\n');
	}
	return 0;
}
