#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
long long fj,ans[10000];
int n,m,len(1);
const long long p=10000000000ll;
void mul(int x){
    long long pre(0),tem;
    for(int i=1;i<=len;i++){
        tem=ans[i]*x;
        ans[i]=tem%p+pre;
        pre=tem/p;
    }
    if(pre){
    	len++;
    	ans[len]=pre;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    ans[1]=1;
    mul(n+1);
    mul(n*(n+3)+2*m);
    for(int i=1;i<=n;i++)
    	mul(i);
    for(int i=n-m+4;i<=n+2;i++)mul(i);
    printf("%lld",ans[len]);
    while(--len)
    	printf("%010lld",ans[len]);
    return 0;
}
