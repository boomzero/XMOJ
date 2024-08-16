#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int r()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1005,M=205,mo=1000000007;
int n,m,K;
bool val=1;
char a[N],b[M];
int f[2][M][M][2];
int main()
{
    n=r();m=r();K=r();
    scanf("%s%s",a+1,b+1);
    f[0][0][0][0]=f[1][0][0][0]=1;
    for(int i=1;i<=n;i++,val^=1){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=K;k++){
                f[val][j][k][0]=(f[val^1][j][k][1]+f[val^1][j][k][0])%mo;
                if(a[i]==b[j]){
                    f[val][j][k][1]=(f[val^1][j-1][k][1]+(f[val^1][j-1][k-1][0]+f[val^1][j-1][k-1][1])%mo)%mo;
                }
                else{
                    f[val][j][k][1]=0;
                }
            }
        }
    }
    printf("%d",(f[n&1][m][K][1]+f[n&1][m][K][0])%mo);
    return 0;
}
