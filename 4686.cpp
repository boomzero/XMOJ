#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define maxn 520
using namespace std;
int n,m,ans,i,j;
int cnt;
int a[maxn][maxn];
bool exist[maxn][maxn];
bool judge[maxn][maxn];
struct node{
    int x;
    int y;
    bool operator<(const node &rhs)const{
        return x < rhs.x;
    }
};
node s[maxn];
int read(){
    int num = 0;
    char c;
    bool flag = false;
    while ((c = getchar()) == ' ' || c == '\n' || c == '\r');
    if (c == '-')
        flag = true;
    else
        num = c - '0';
    while (isdigit(c = getchar()))
        num = num * 10 + c - '0';
    return (flag ? -1 : 1) * num;
}
void dfs(int x,int y){
    if (exist[x][y])
        return;
    exist[x][y] = true;
    if (x+1 <= n && a[x][y] > a[x+1][y])
        dfs(x+1,y);
    if (x-1 >= 1 && a[x][y] > a[x-1][y])
        dfs(x-1,y);
    if (y + 1 <= m && a[x][y] > a[x][y+1])
        dfs(x,y+1);
    if (y - 1 >= 1 && a[x][y] > a[x][y-1])
        dfs(x,y-1);
}
int main(){
	freopen("flow.in","r",stdin);
	freopen("flow.out","w",stdout);
    n = read();m = read();
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            a[i][j] = read();
    for (i=1;i<=m;i++){
        memset(exist,0,sizeof(exist));
        dfs(1,i);
        for (j=1;j<=m;j++)
            judge[i][j] = exist[n][j];
    }
    cnt = m;
    for (i=1;i<=m;i++)
        for (j=1;j<=m;j++)
            if (judge[j][i]){
                cnt--;
                break;
            }
    if (cnt > 0){
        printf("0\n%d",cnt);
        return 0;
    }
    for (i=1;i<=m;i++){
        for (j=1;j<=m;j++)
            if (judge[i][j])
                break;
        s[i].x = j;
        for (j = s[i].x + 1;j<=m;j++)
            if (!judge[i][j])
                break;
        s[i].y = j-1;
    }
    sort(s+1,s+m+1);
    int maxv = 0;
    int tmp = 0;
    for (i=1;i<=m;i++){
        if (s[i].x > m)
            break;
        if (s[i].x <= maxv + 1)
            tmp = max(tmp,s[i].y);
        else{
            maxv = tmp;
            ans++;
            tmp = max(s[i].y,tmp);
        }
    }
    if (maxv != m)
        ans++;
    printf("1\n%d",ans);
    return 0;
}
