#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
const int maxn=100010;
int A[maxn],cnt,ans[maxn];
int mx[maxn][20],mn[maxn][20],Log[maxn];
void query(int l,int r,int& p1,int& p2) {
    int k=Log[r-l+1];
    p1=A[mx[l][k]]>A[mx[r-(1<<k)+1][k]]?mx[l][k]:mx[r-(1<<k)+1][k];
    p2=A[mn[l][k]]<A[mn[r-(1<<k)+1][k]]?mn[l][k]:mn[r-(1<<k)+1][k];
}
void solve(int l,int r) {
    if(l+1>=r)
    	return;
    int p1,p2;
    query(l+1,r-1,p1,p2);
    if(A[p2]<min(A[l],A[r]))
    	ans[++cnt]=p2,solve(l,p2),solve(p2,r);
    else if(A[p1]>max(A[l],A[r]))
    	ans[++cnt]=p1,solve(l,p1),solve(p1,r);
}
int main() {
	freopen("typeface.in", "r", stdin);
	freopen("typeface.out", "w", stdout);
    int n=read();
    for(int i=1;i<=n;i++)
    	A[i]=read();
    Log[0]=-1;
    for(int i=1;i<=n;i++)
    	Log[i]=Log[i>>1]+1;
    for(int i=1;i<=n;i++)
    	mx[i][0]=mn[i][0]=i;
    for(int j=1;(1<<j)<=n;j++) 
        for(int i=1;i+(1<<j)-1<=n;i++) {
            int v1=mx[i][j-1],v2=mx[i+(1<<j-1)][j-1];
            mx[i][j]=A[v1]>A[v2]?v1:v2;
            v1=mn[i][j-1];
            v2=mn[i+(1<<j-1)][j-1];
            mn[i][j]=A[v1]<A[v2]?v1:v2;
        }
    ans[++cnt]=1;ans[++cnt]=n;
    solve(1,n);
    printf("%d\n",cnt);
    sort(ans+1,ans+cnt+1);
    printf("%d",ans[1]);
    for(int i=2;i<=cnt;i++)
    	printf(" %d",ans[i]);
    return 0;
}
