#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6,mod=1e9+7;
ll n,T[N+1],p[N+1],tt,x,sum[N+1],ans;
inline ll read(){
	char c=getchar();
	ll s=1;
	for(;!('0'<=c&&c<='9'||c=='-');
	c=getchar());
	if(c=='-'){
		s=-1;
		c=getchar();
	}
	ll num=0;
	while('0'<=c&&c<='9'){
		num=num*10+(c-'0');
		c=getchar();
	}
	num=num*s;
	return num;
}
int main(){
	ll i,j;
	memset(T,0,sizeof(T));
	n=read();
	for(i=2;i<=n;i++){
		if(T[i]==0){
			p[++tt]=i;
			T[i]=tt;
			for(j=i+i;j<=n;j+=i)
				T[j]=-1;
		}
	}
	for(i=1;i<=n;i++){
		x=i;
		for(j=1;p[j]*p[j]<=x;j++)
			while(x%p[j]==0)
				x/=p[j],sum[j]++,sum[j]%=mod;
		if(x>1)
			sum[T[x]]++,sum[T[x]]%=mod;
	}
	ans=1;
	for(j=1;j<=tt;j++)
		ans*=sum[j]*2+1,ans%=mod;
	printf("%lld",ans);
	return 0;
}
