#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
int main()
{
	freopen("b.in","r",stdin) ;
	freopen("b.out","w",stdout) ;
	scanf("%lld%lld%lld",&a,&b,&c);
	long long ans=max(a,max(b,c))-min(a,min(b,c));
	printf("%lld",ans);
	return 0 ;
}
