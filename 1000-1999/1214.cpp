#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	long long a,b,ans;
	scanf("%lld%lld",&a,&b);
	ans=a*b-a-b;
	printf("%lld",ans);
	return 0;
}
