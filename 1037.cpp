#include<bits/stdc++.h>
using namespace std;
const int N=40005,M=15005;
int x[N],z[N][5],sum[M];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>x[i];
		++sum[x[i]];
	}
	for(int k=1;k*9<n;++k){
		int pre=0;
		int a,b,c,d;
		for(d=k*9+2;d<=n;++d){
			a=d-9*k-1;
			b=d-7*k-1;
			c=d-k;
			pre+=sum[b]*sum[a];
			z[c][3]+=sum[d]*pre;
			z[d][4]+=sum[c]*pre;
		}
		pre=0;
		for(a=n-k*9-1;a>=1;--a){
			b=a+2*k;
			c=a+k*8+1;
			d=a+k*9+1;
			pre+=sum[c]*sum[d];
			z[a][1]+=sum[b]*pre;
			z[b][2]+=sum[a]*pre;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<z[x[i]][1]<<' '<<z[x[i]][2]<<' '<<z[x[i]][3]<<' '<<z[x[i]][4]<<'\n';
	}
	return 0;
}
