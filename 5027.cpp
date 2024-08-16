#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x)
const int MAXN=1e5+5;
const int MAXM=2e4+5;
int a[MAXN][2],sum[MAXM];
void add(int x,int val){
	++x;
	while(x<MAXM)
		sum[x]+=val,x+=lowbit(x);
}
int ask(int x){
    ++x;
    int ret=0;
    while(x) ret+=sum[x],x-=lowbit(x);
    return ret;
}
int query(int x){
	return ask(MAXM-2)-ask(x);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
    	scanf("%d %d",&a[i][0],&a[i][1]);
    	add(0,1),add(a[i][0],1);
    	add(a[i][1],1),add(a[i][0]+a[i][1],1);
    }
    for(int i=1;i<=n;++i){
        add(0,-1),add(a[i][0],-1),add(a[i][1],-1),add(a[i][0]+a[i][1],-1);
        double ans=(double)(query(0)+query(a[i][0])+query(a[i][1])+query(a[i][0]+a[i][1]))/16+1;
        printf("%.6lf\n",ans);
        add(0,1),add(a[i][0],1);
        add(a[i][1],1),add(a[i][0]+a[i][1],1);
    }
    return 0;
}
