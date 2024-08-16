#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
const long long Z=1e9+7;
long long f[N]; 
long long f1[N],f2[N],cnt1,cnt2;
long long x[N],y[N],z[N];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
long long ksm(long long base,long long p){
	long long ans=1;
	while(p){
		if(p&1) ans*=base;
		base*=base;
		p>>=1;
	}
	return ans;
}
int main(){
	long long T;cin>>T;
	while(T--){
		long long n,h,r;
		cin>>n>>h>>r;
		cnt1=cnt2=0;
		for(int i=1;i<=n;++i) f[i]=i;
		for(long long i=1;i<=n;++i){
			cin>>x[i]>>y[i]>>z[i];
			if(z[i]+r>=h) f1[++cnt1]=i;
			if(z[i]-r<=0) f2[++cnt2]=i;
		}
		for(long long i=1;i<=n;++i){
			for(long long j=i+1;j<=n;++j){
				long long fx=find(i);
				long long fy=find(j);
				if(fx==fy)
					continue;
				long long dist=ksm(x[i]-x[j],2)+ksm(y[i]-y[j],2)+ksm(z[i]-z[j],2);
				long long rdist=r*r*4;
				if(dist<=rdist) f[fx]=fy;
			}
		}
		bool flag=0;
		for(long long i=1;i<=cnt1;++i)
		{
			for(long long j=1;j<=cnt2;++j)
			{
				if(find(f1[i])==find(f2[j]))
				{
					flag=1; 
					break;
				}
			}
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
 	return 0;		
}
