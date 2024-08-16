#include <bits/stdc++.h>
using namespace std;
int n;
long long fib[100];
int main(){
	freopen("fib.in","r",stdin);
	freopen("fib.out","w",stdout);
	scanf("%d",&n);
	fib[0]=2,fib[1]=1;
	for(int i=2;i<=n;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	printf("%lld",fib[n]);
    return 0;
}
