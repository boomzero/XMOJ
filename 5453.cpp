#include<bits/stdc++.h>
using namespace std;
int n,m,c[105],p[105],w[105][55],f[105][10005],s[105][10005],x[105],maxn=0;
int main(){
    int i,j,k;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>c[i]>>p[i];
        for(j=1;j<=p[i];j++){
            cin>>w[i][j];
        }
    }
    for(j=1;j<=m;j++){
        for(i=1;i<=n;i++){
        f[i][j]=f[i-1][j];
            for(k=1;k<=p[i];k++){
                if(j>=c[i]*k){
                    if(f[i-1][j-c[i]*k]+w[i][k]>f[i][j]){
                        f[i][j]=f[i-1][j-c[i]*k]+w[i][k];
                        s[i][j]=k;
                    }
                }
            }
        }
    }
    cout<<f[n][m]<<endl;
    for(int i=1;i<=m;i++) {
        if(f[n][i]>f[n][maxn]){
            maxn=i;
        } 
    }
    int l=n,t=maxn;
    while(l!=0){
        x[l]=s[l][t];
        t-=s[l][t]*c[l];
        l--;
    }
    for(i=1;i<=n;i++){
        cout<<x[i]<<endl;
    }
    return 0;
}
