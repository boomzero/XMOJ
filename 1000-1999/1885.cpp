#include<cstdio>
using namespace std;
int n,m,k,x;
int qpow(int a,int b)
{
    int ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(ans*a)%n;
        a=(a*a)%n;
        b>>=1;
    }
    return ans%n;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&x);
    printf("%d",(x%n+m*qpow(10,k))%n);
    return 0;
}
