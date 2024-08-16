#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s,q;
long long a[1000038],t[50238],sum[51000],mx[5010];
vector<int> vec[50010];
#define blo(i) (i-1)/s+1
void change(int x) {
	int y=blo(x);
	vec[y].clear();
	for(int i=(y-1)*s+1;i<=y*s;i++){
		vec[y].push_back(a[i]);
	}
	sort(vec[y].begin(),vec[y].end());
}
signed main(){
	scanf("%lld%lld",&n,&q);
	s=sqrt(n);m=(n-1)/s+1;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),sum[blo(i)]+=a[i],mx[blo(i)]=max(mx[blo(i)],a[i]),vec[blo(i)].push_back(a[i]);
	for(int i=1;i<=m;i++)
		sort(vec[i].begin(),vec[i].end());
	for(int j=1;j<=q;j++){
		int x,l,r,c;
		char op[5];
		scanf("%s%lld%lld%lld",op,&l,&r,&c);
		if(op[0]=='M'){
			int i=l;
			for(;i<=min(((l-1)/s+1)*s,r);i++)
				a[i]+=c; 
			change(i-1);
			for(;i<=(r-1)/s*s;i+=s) {
				t[blo(i)]+=c;
			}
			for(;i<=r;i++)a[i]+=c;
			change(i-1); 
		}
		else {
			// c=c*c;
			int i=l;
			long long ans=0;
			for(;i<=min(((l-1)/s+1)*s,r);i++)
				if(a[i]+t[blo(i)]>=c)
					ans++;
			for(;i<=(r-1)/s*s;i+=s)
				ans+=vec[blo(i)].end()-lower_bound(vec[blo(i)].begin(),vec[blo(i)].end(),c-t[blo(i)]);
			for(;i<=r;i++)
				if(a[i]+t[blo(i)]>=c)
					ans++;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
