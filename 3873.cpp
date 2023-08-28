#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,a[N][N];
long long f[N],u[N],d[N];
inline int read(){
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return f*x;
}
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);//
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            a[i][j]=read();
    f[1]=a[1][1];
    for(int i=2;i<=n;++i) f[i]=f[i-1]+a[i][1];
    for(int j=2;j<=m;++j) {
        d[1]=f[1]+a[1][j];
        for(int i=2;i<=n;++i) d[i]=max(f[i],d[i-1])+a[i][j];
        u[n]=f[n]+a[n][j];
        for(int i=n-1;i>=1;--i) u[i]=max(f[i],u[i+1])+a[i][j];
        for(int i=1;i<=n;++i) f[i]=max(d[i],u[i]);
    }
    printf("%lld\n",f[n]);
    return 0;
}

