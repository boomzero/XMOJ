#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;

const int maxn = 200000 + 100;
int n,m;
ll S;
int L[maxn],R[maxn],val[maxn],w[maxn];
int sum[maxn],dis[maxn];
ll ans;

int read() {
    int x = 0, t = 1;
    char ch = getchar();
    while(ch < '0' || ch >'9'){
        if(ch == '-') t = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * t;
}

bool pd(int mid) {
	memset(sum,0,sizeof(sum));
	memset(dis,0,sizeof(dis));
	ll now = 0;
	for(int i = 1; i <= n; i++) {
		if(w[i] >= mid)	sum[i] = sum[i-1] + val[i],dis[i] = dis[i-1] + 1;
		else sum[i] = sum[i-1],dis[i] = dis[i-1];
	}
	for(int i = 1; i <= m; i++) {
		int p = sum[R[i]] - sum[L[i]];
		int q = dis[R[i]] - dis[L[i]];
		now += (ll)p * q;
	}
	ll p = abs(now - S);
	ans = min(ans,p);
	return now - S > 0;
}

int main() {
	freopen("qc.in","r",stdin);
	freopen("qc.out","w",stdout);
	n = read(), m = read();
	cin>>S;
	ans = S;
	for(int i = 1; i <= n; i++)	w[i] = read(), val[i] = read();
	for(int i = 1; i <= m; i++)	L[i] = read() - 1, R[i] = read();
	int l = 0, r = 1e6;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(pd(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout<<ans;
	return 0;
}

