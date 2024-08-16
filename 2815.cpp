#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<ctime>
#define MAXN 50010
using namespace std;
int n,m,q,block;
int val[MAXN],lsh[MAXN];
long long s=0,ans[MAXN];
struct Question{
	int l,r,id;
	friend bool operator <(const Question &p,const Question &q){
		return (p.r/block==q.r/block?(((p.r/block)&1)?p.l>q.l:p.l<q.l):p.r<q.r);
	}
}que[MAXN];
inline int read(){
	int date=0;char c=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){date=date*10+c-'0';c=getchar();}
	return date;
}
namespace BIT{
	long long bit[MAXN];
	inline int lowbit(int x){return x&(-x);}
	inline void add(int x,int v){for(;x<=q;x+=lowbit(x))bit[x]+=v;}
	inline long long sum(int x){long long s=0;for(;x;x-=lowbit(x))s+=bit[x];return s;}
}
inline void add_left(int x){
	s+=BIT::sum(x-1);
	BIT::add(x,1);
}
inline void del_left(int x){
	BIT::add(x,-1);
	s-=BIT::sum(x-1);
}
inline void add_right(int x){
	s+=BIT::sum(q)-BIT::sum(x);
	BIT::add(x,1);
}
inline void del_right(int x){
	BIT::add(x,-1);
	s-=BIT::sum(q)-BIT::sum(x);
}
void work(){
	int left=1,right=0;
	for(int i=1;i<=m;i++){
		while(left<que[i].l)del_left(val[left++]);
		while(left>que[i].l)add_left(val[--left]);
		while(right<que[i].r)add_right(val[++right]);
		while(right>que[i].r)del_right(val[right--]);
		ans[que[i].id]=s;
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
}
void init(){
	n=read();
	for(int i=1;i<=n;i++)val[i]=lsh[i]=read();
	sort(lsh+1,lsh+n+1);
	q=unique(lsh+1,lsh+n+1)-lsh-1;
	for(int i=1;i<=n;i++)val[i]=lower_bound(lsh+1,lsh+q+1,val[i])-lsh;
	m=read();
	block=sqrt(n);
	for(int i=1;i<=m;i++){
		que[i].l=read();que[i].r=read();
		que[i].id=i;
	}
	sort(que+1,que+m+1);
}
int main(){
	init();
	work();
	return 0;
}
