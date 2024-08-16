#include<bits/stdc++.h>
using namespace std;
int m,n,tot,color,ans=0x7fffffff;
char s[52][52];
bool flag[52][52];
int dis[20][2502],maps[52][52],f[70000][20];
typedef pair<int,int> xy;
xy rep[2502];
queue<xy> q;
void dfs(int x,int y)
{
    if (flag[x][y]) return;
    flag[x][y]=1;
    if (x+1<=n&&s[x+1][y]=='X') dfs(x+1,y);
    if (x-1>0&&s[x-1][y]=='X') dfs(x-1,y);
    if (y+1<=m&&s[x][y+1]=='X') dfs(x,y+1);
    if (y-1>0&&s[x][y-1]=='X') dfs(x,y-1);
}
int main()
{
	freopen("island.in", "r", stdin);
	freopen("island.out", "w", stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    if (s[i][j]=='X'&&!flag[i][j])
    {
        rep[++tot].first=i;
        rep[tot].second=j;
        maps[i][j]=tot;
        dfs(i,j);
    }
    color=tot;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    if (!maps[i][j])
    rep[++tot].first=i,
    rep[tot].second=j,
    maps[i][j]=tot;
    memset(flag,0,sizeof(flag));
    for (int i=1;i<=color;i++)
    {
        memset(dis[i],63,sizeof(dis[i]));
        dis[i][i]=0;
        q.push(rep[i]);
        while (!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            if (x+1<=n&&s[x+1][y]!='.'&&dis[i][maps[x+1][y]]>dis[i][maps[x][y]]+(s[x+1][y]=='S'))//(x,y)->(x+1,y)
            {
                dis[i][maps[x+1][y]]=dis[i][maps[x][y]]+(s[x+1][y]=='S');
                if (!flag[x+1][y]) q.push(rep[maps[x+1][y]]),flag[x+1][y]=1;
            }
            if (x-1>0&&s[x-1][y]!='.'&&dis[i][maps[x-1][y]]>dis[i][maps[x][y]]+(s[x-1][y]=='S'))//(x,y)->(x-1,y)
            {
                dis[i][maps[x-1][y]]=dis[i][maps[x][y]]+(s[x-1][y]=='S');
                if (!flag[x-1][y]) q.push(rep[maps[x-1][y]]),flag[x-1][y]=1;
            }
            if (y+1<=m&&s[x][y+1]!='.'&&dis[i][maps[x][y+1]]>dis[i][maps[x][y]]+(s[x][y+1]=='S'))//(x,y)->(x,y+1)
            {
                dis[i][maps[x][y+1]]=dis[i][maps[x][y]]+(s[x][y+1]=='S');
                if (!flag[x][y+1]) q.push(rep[maps[x][y+1]]),flag[x][y+1]=1;
            }
            if (y-1>0&&s[x][y-1]!='.'&&dis[i][maps[x][y-1]]>dis[i][maps[x][y]]+(s[x][y-1]=='S'))//(x,y)->(x,y-1)
            {
                dis[i][maps[x][y-1]]=dis[i][maps[x][y]]+(s[x][y-1]=='S');
                if (!flag[x][y-1]) q.push(rep[maps[x][y-1]]),flag[x][y-1]=1;
            }
            flag[x][y]=0;
        }
    }
    memset(f,63,sizeof(f));
    for (int i=1;i<=color;i++) f[1<<i-1][i]=0;
    for (int i=1;i<=(1<<color)-1;i++)
    for (int j=1;j<=color;j++)
    if (i&(1<<j-1))
    {
        for (int k=1;k<=color;k++)
        if ((i&(1<<k-1))==0) 
        f[i+(1<<k-1)][k]=min(f[i+(1<<k-1)][k],f[i][j]+dis[j][k]);
    }
    for (int i=1;i<=color;i++)
    ans=min(ans,f[(1<<color)-1][i]);
    printf("%d",ans);
}
