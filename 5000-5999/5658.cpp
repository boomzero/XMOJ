#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=40010;

int n,N,a[maxn],last[maxn],c[maxn],b[maxn],f[maxn],m,top;
int main(){
    scanf("%d%d",&n,&N);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    m=(int)sqrt(n)+1;
    top=0;
    for(int i=1;i<=n;i++){
        last[i]=c[a[i]];
        c[a[i]]=i;
        for(int j=1;j<=min(m,top);j++)if(last[i]<b[j]){
            while(c[a[b[j]]]!=b[j])b[j]++;
            b[j]++;
        }
        if(!last[i])b[++top]=1;
        f[i]=i;
        for(int j=1;j<=min(m,top);j++)f[i]=min(f[i],f[b[j]-1]+j*j);
    }
    printf("%d",f[n]);
    return 0;
}
