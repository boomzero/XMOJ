#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long t,n,i,j,k,ans,mx,mxp,a[N];
struct Stack {
	long long a[N],c[N];
	void init() {
		memset(a,0,sizeof a);
		memset(c,0,sizeof c);
	}
	Stack(){
		init();
	}
	void push(long long v) {
		long long k=0;
		while (a[0] && v>a[a[0]]) {
			ans+=c[a[0]]; 
			c[0]-=c[a[0]]; 
			c[a[0]--]=0; 
		}
		if (!a[0] || a[a[0]]!=v)
			a[++a[0]]=v;
		c[a[0]]++,c[0]++;
		ans+=c[a[0]]-1;
		if (a[0]>=2) 
			ans++;
	}
	void fin(){
		while(a[0]>=2 && c[1]>=2 || a[0]>=3){
			c[0]-=c[a[0]];
			ans+=c[a[0]--];
		}
	}
}stk;
int main(){
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ans=mx=0,stk.init();
		for (int i=1; i<=n; i++){
			scanf("%lld",a+i);
			if (a[i]>mx)
				mx=a[i],mxp=i;
		}
		stk.push(mx);
		for (int i=mxp%n+1; i!=mxp; i++) {
			stk.push(a[i]);
			if (i+1>n)
				i=0;
		}
		stk.fin();
		printf("%lld\n",ans);
	}
	return 0;
}
