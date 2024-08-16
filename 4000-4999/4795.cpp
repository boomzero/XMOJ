#include <bits/stdc++.h>
using namespace std;
int y,T;
long long n,m,k;
long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main(){
	freopen("show.in","r",stdin);
	freopen("show.out","w",stdout);
	scanf("%d",&y);
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%lld%lld%lld",&n,&m,&k);
		if(m%k==0||m==0){
			printf("Case %d: Yes\n",i+1);
			continue;
		}
//		else if(n+m==k){
//			printf("Case %d: No\n",i+1);
//			continue;
//		}
		else if(n+m<=k&&m>0){
			printf("Case %d: No\n",i+1);
			continue;
		}
		else if(m%2==1&&k%2==0){
			printf("Case %d: No\n",i+1);
			continue;
		}
//		else if(m+n-1==k){
//			printf("Case %d: No\n",i+1);
//			continue;
//		}
//		else if(gcd(m,k)==1){
//			printf("Case %d: No\n",i+1);
//			continue;
//		}
//		else if(gcd(n+m-k*((n+m)/k),m)!=1){
//			printf("Case %d: Yes\n",i+1);
//			continue;
//		}
		printf("Case %d: Yes\n",i+1);
	}
	return 0;
}
