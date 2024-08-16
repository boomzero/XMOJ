#include<bits/stdc++.h>
using namespace std;
int n,m,f,fa[405];
long long mid,l,r=2e15;
struct Road{
	int x,y,c,t;
	double w;
}road[10005];
inline int fnd(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=fnd(fa[x]);
}
inline bool cmp(Road a,Road b){
	return a.w<b.w;
}
inline bool check(long long mid){
	for(int i=1;i<=m;i++)
		road[i].w=mid/(3e6+0.0)*road[i].t+road[i].c;
	int tmp=1;
	sort(road+1,road+m+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	double k=f+1e-12;
	for(int i=2;i<=n;i++){
		while(tmp<=m&&fnd(road[tmp].x)==fnd(road[tmp].y))
			tmp++;
		fa[fnd(road[tmp].x)]=fnd(road[tmp].y),k-=road[tmp].w;
		if(k<0)
			return false;
	}
	return true;
}
inline int rd(){
	int ret=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=(ret<<1)+(ret<<3)+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
int main(){
	n=rd();
	m=rd();
	f=rd();
	for(int i=1;i<=m;i++){
		road[i].x=rd();
		road[i].y=rd();
		road[i].c=rd();
		road[i].t=rd();
	}
	if(!check(0)){
		printf("0.0000");
		return 0;
	}
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid+1))
			l=mid+1;
		else
			r=mid;
	}
	printf("%0.4lf",l/(3e6+0.0));
	return 0;
}
