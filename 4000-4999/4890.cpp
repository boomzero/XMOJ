#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=8005;
int n,q;
int t[MAXN];
struct node{
	int pre,id;
}a[MAXN];
bool cmp(node x,node y){
	if(x.pre!=y.pre) return x.pre<y.pre;
	return x.id<y.id;
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	scanf("%d%d",&n,&q); 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].pre);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		t[a[i].id]=i;
	for(int i=1;i<=q;i++){
		int opt,x,v;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&x,&v);
			a[t[x]].pre=v;
			for(int j=n;j>=2;j--)
				if(cmp(a[j],a[j-1])){
					node kkksc03=a[j];
					a[j]=a[j-1];
					a[j-1]=kkksc03;
				}
			for(int j=2;j<=n;j++)
				if(cmp(a[j],a[j-1])){
					node kkksc03=a[j];
					a[j]=a[j-1];
					a[j-1]=kkksc03;
				}
			for(int i=1;i<=n;i++)
				t[a[i].id]=i;
		}
		else{
			scanf("%d",&x);
			printf("%d\n",t[x]);
		}
	}
	return 0;
}
