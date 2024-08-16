#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int score[360],f[42][42][42][42];
int main(){
	freopen("tortoise.in","r",stdin);
	freopen("tortoise.out","w",stdout);
	ios::sync_with_stdio(false);
    int n,m,x;
    int a=0,b=0,c=0,d=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>score[i];
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        if(x==1) a++;
        if(x==2) b++;
        if(x==3) c++;
        if(x==4) d++;
    }
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=c;k++){
                for(int t=0;t<=d;t++){
                    int s=i+j*2+k*3+t*4+1;
                    if(i)
                    	f[i][j][k][t]=max(f[i][j][k][t],f[i-1][j][k][t]+score[s]);
                    if(j)
                    	f[i][j][k][t]=max(f[i][j][k][t],f[i][j-1][k][t]+score[s]);
                    if(k)
                    	f[i][j][k][t]=max(f[i][j][k][t],f[i][j][k-1][t]+score[s]);
                    if(t)
                    	f[i][j][k][t]=max(f[i][j][k][t],f[i][j][k][t-1]+score[s]);
                }
            }
        }
    }
    cout<<f[a][b][c][d]+score[1];
    return 0;
}
