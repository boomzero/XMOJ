#include<bits/stdc++.h>
using namespace std;
int n,m,q,u,v,t,a[100005];
queue<int>Q[4];
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>=1;--i)
		Q[1].push(a[i]);
	int del=0,tot=0;
	for(int i=1;i<=m;++i){
		int Max=-1000000000,p=0;
		if(!Q[1].empty()&&Q[1].front()>Max)
			Max=Q[1].front(),p=1;
		if(!Q[2].empty()&&Q[2].front()>Max)
			Max=Q[2].front(),p=2;
		if(!Q[3].empty()&&Q[3].front()>Max)
			Max=Q[3].front(),p=3;
		Q[p].pop(),Max+=del,del+=q;
		if(i%t==0)  printf("%d ",Max);
		int L=1ll*Max*u/v,R=Max-L;
		L-=del,R-=del;
		Q[2].push(L),Q[3].push(R);
	}
	puts("");
	for(int i=1;i<=n+m;++i){
		int Max=-1000000000,p=0;
		if(!Q[1].empty()&&Q[1].front()>Max)
			Max=Q[1].front(),p=1;
		if(!Q[2].empty()&&Q[2].front()>Max)
			Max=Q[2].front(),p=2;
		if(!Q[3].empty()&&Q[3].front()>Max)
			Max=Q[3].front(),p=3;
		Q[p].pop();
		if(i%t==0)
			printf("%d ",Max+del);
	}
	return 0;
}
