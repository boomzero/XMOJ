#include <bits/stdc++.h>
using namespace std;
int n,data[9][9],row[9],col[9],diagonal1,diagonal2,vis[100],flag=0,sum,avg;
void dfs(int x,int y)
{
    if (x==n-1&&y==n) {
        if (diagonal1!=avg||diagonal2!=avg) return;
        flag=1;
        for (int i=0;i<n;++i) {
            cout<<data[i][0];
            for (int j=1;j<n;++j) cout<<" "<<data[i][j];
            cout<<endl;
        }
        return;
    }
    if (flag) return;
    if (x==n-1&&y>0&&col[y-1]!=avg) return;
    if (y==n) {
        if (row[x]==avg)
            dfs(x+1,0);
        return;
    }
    if (data[x][y]>0) {
        dfs(x,y+1);
        return;
    }
    for (int i=1;i<=n*n;++i) {
        if (vis[i]) continue;
        if (row[x]+i>avg&&col[y]+i>avg) continue;
        if (x==y&&diagonal1+i>avg) continue;
        if (x+y==n-1&&diagonal2+i>avg) continue;
        data[x][y]=i;
        vis[i]=1;
        row[x]+=i;
        col[y]+=i;
        if (x==y) diagonal1+=i;
        if (x+y==n-1) diagonal2+=i;
        dfs(x,y+1);
        data[x][y]=0;
        vis[i]=0;
        row[x]-=i;
        col[y]-=i;
        if (x==y) diagonal1-=i;
        if (x+y==n-1) diagonal2-=i;
    }
}
int main()
{
    int x;
    cin>>n;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j) {
            cin>>x;
            if (x>0) {
                data[i][j]=x;
                vis[x]=1;
                row[i]+=x;
                col[j]+=x;
                if (i==j) diagonal1+=x;
                if (i+j==n-1) diagonal2+=x;
            } else data[i][j]=0;
        }
    for (int i=1;i<=n*n;++i)
        sum+=i;
    avg=sum/n;
    dfs(0,0);
    return 0;
}
