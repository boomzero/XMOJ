#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
int block,n,m,opt,l,r,id[maxn];
ll a[maxn],tag[1005],sum_d[1005];
void cht_md(int x){
	ll res=0;
	int L=(x-1)*block+1,R=x*block;
	bool flag=true;
	for(int i=L;i<=R;i++){
		if(a[i]==1){res++;continue;}
		a[i]=(ll)floor(sqrt(a[i]));
		if(a[i]!=1) flag=false;
		res+=a[i];
	}
	if(flag) tag[x]=1;
	sum_d[x]=res;
}
void change(int l,int r){
	//left
	for(int i=l;i<=min(r,id[l]*block);i++)
		sum_d[id[i]]-=a[i],a[i]=(ll)floor(sqrt(a[i])),sum_d[id[i]]+=a[i];
	if(id[l]==id[r]) return ;
	//middle
	for(int i=id[l]+1;i<=id[r]-1;i++)
		if(!tag[i]) cht_md(i);
	//right
	for(int i=(id[r]-1)*block+1;i<=r;i++)
		sum_d[id[i]]-=a[i],a[i]=(ll)floor(sqrt(a[i])),sum_d[id[i]]+=a[i];
}
ll query(int l,int r){
	ll res=0;
	//left
	for(int i=l;i<=min(r,id[l]*block);i++)
		res+=a[i];
	if(id[l]==id[r]) return res;
	//middle
	for(int i=id[l]+1;i<=id[r]-1;i++) res+=sum_d[i];
	//right
	for(int i=(id[r]-1)*block+1;i<=r;i++) res+=a[i];
	return res;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d",&n);
	block=(int)floor(sqrt(n));
	for(int i=1;i<=n;i++){
		id[i]=(i-1)/block+1;
		scanf("%lld",&a[i]);
		sum_d[id[i]]+=a[i];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&opt,&l,&r);
		if(l>r) swap(l,r);
		if(opt==0) change(l,r);
		else printf("%lld\n",query(l,r));
	}
	return 0;
}
//为什么第二题会用到分块啊啊啊啊啊啊！
