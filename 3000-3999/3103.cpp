#include<bits/stdc++.h>
using namespace std;
int n,m,K,x,f[110][110],F[110][110][110],sum[4][110];
int main()
{
    scanf("%d%d%d",&n,&m,&K);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&x),sum[j][i]=sum[j][i-1]+x;
    if(m==1)
    {
        for(int k=1;k<=K;k++)
            for(int i=1;i<=n;i++)
            {
                f[i][k]=f[i-1][k];
                for(int j=0;j<i;j++)
                    f[i][k]=max(f[i][k],f[j][k-1]+sum[1][i]-sum[1][j]);
            }
        printf("%d",f[n][K]);
        return 0;
    }
    else if(m==2)
    {
        for(int k=1;k<=K;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    F[i][j][k]=max(F[i-1][j][k],F[i][j-1][k]);
                    for(int l=0;l<i;l++) 
                        F[i][j][k]=max(F[i][j][k],F[l][j][k-1]+sum[1][i]-sum[1][l]);
                    for(int l=0;l<j;l++)
                        F[i][j][k]=max(F[i][j][k],F[i][l][k-1]+sum[2][j]-sum[2][l]);
                    if(i==j)
                        for(int l=0;l<i;l++)
                            F[i][j][k]=max(F[i][j][k],
                                    F[l][l][k-1]+sum[1][i]-sum[1][l]+sum[2][j]-sum[2][l]);
                }
        printf("%d",F[n][n][K]);
    }
    return 0;
}
