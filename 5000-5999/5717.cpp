#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100005
#define PLI pair<long long,int>
#define fi first
#define se second
#define mp make_pair
//#define ivorysi
using namespace std;
typedef long long int64;
int N;
int64 C,x[MAXN],v[MAXN],ans;
int64 pre[MAXN],suf[MAXN],premax[MAXN],sufmax[MAXN];
void Solve() {
	scanf("%d%lld",&N,&C);
	for(int i = 1 ; i <= N ; ++i) scanf("%lld%lld",&x[i],&v[i]);
	x[N + 1] = C;
	for(int i = 1 ; i <= N ; ++i) {
		pre[i] = pre[i - 1] + v[i] - (x[i] - x[i - 1]);
		premax[i] = max(pre[i],premax[i - 1]);
	}
	for(int i = N ; i >= 1 ; --i) {
		suf[i] = suf[i + 1] + v[i] - (x[i + 1] - x[i]);
		sufmax[i] = max(suf[i],sufmax[i + 1]);
	}
	ans = max(ans,max(sufmax[1],premax[N]));
	for(int i = 1 ; i <= N ; ++i) {
		ans = max(ans,pre[i] - x[i] + sufmax[i + 1]);
	}
	for(int i = N ; i >= 1 ; --i) {
		ans = max(ans,suf[i] - (C - x[i]) + premax[i - 1]);
	}
	printf("%lld\n",ans);
}
int main() {
freopen("eat.in","r",stdin);
freopen("eat.out","w",stdout);
	Solve();
	return 0;
}

