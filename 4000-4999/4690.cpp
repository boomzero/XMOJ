#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){int x=0,f=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')f=-1;
ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<1)+
(x<<3)+(ch^48);ch=getchar();}return x*f;}
#define M 10007
int n, m, i, j, k; 
int a, b, J[2000010]; 
int K(int a, int b)
{
	int ans=1; 
	while(b)
	{
		if(b&1) ans=(ans*a)%M; 
		a=(a*a)%M; 
		b>>=1; 
	}
	return ans; 
}
int C(int n, int m)
{
	if(m==0) return 1; 
	return J[n]*K(J[m]*J[n-m]%M ,M-2)%M; 
}
signed main()
{
	freopen("factor.in","r",stdin);
	freopen("factor.out","w",stdout); 
	for(i=J[0]=1; i<=2000000; ++i) J[i]=J[i-1]*i%M; 
	scanf("%lld%lld%lld%lld%lld", &a, &b, &k, &n, &m); 
	printf("%lld", K(a, n)*K(b, m)%M*C(k, n)%M); 
	return 0;
}

