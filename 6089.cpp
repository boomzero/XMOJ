#include<cstdio>
#include<cmath>
#include<cstring>
#define min(a,b) (a)<(b)?(a):(b);
#define ll long long
const int maxn=305;
const ll inf=(ll)2e9;
int n,m,k;
ll dp[maxn][maxn][2][2][2][2];
ll dfs(int x,int y,bool up,bool down,bool left,bool right){ //bool 类型记录是否四个方向沿海 
	if(dp[x][y][up][down][left][right]!=-1) return dp[x][y][up][down][left][right]; //正常 
	if(dp[x][y][down][up][right][left]!=-1) return dp[x][y][down][up][right][left]; //倒立 
	if(dp[y][x][left][right][down][up]!=-1) return dp[y][x][left][right][down][up]; //往左转 
	if(dp[y][x][right][left][up][down]!=-1) return dp[y][x][right][left][up][down]; //往右转 
	if(!(up||down||left||right)) return inf; //不沿海 
	ll ans1=pow(x*y-k,2);
	if(x==1&&y==1||x*y<k) return dp[x][y][up][down][left][right]=ans1;
	ll ans2=inf;
	bool u1,u2,d1,d2,l1,l2,r1,r2;
	//横着分开 
	if(x>1&&(up&&down||left||right)){
		u1=up,u2=0,d1=0,d2=down,l1=l2=left,r1=r2=right;
		for(register int i=1;i<x;i++){
			int t=dfs(i,y,u1,d1,l1,r1)+dfs(x-i,y,u2,d2,l2,r2);
			ans2=min(ans2,t);
		}
	}
	//竖着分开 
	if(y>1&&(left&&right||up||down)){
		u1=u2=up,d1=d2=down,l1=left,l2=0,r1=0,r2=right;
		for(register int i=1;i<y;i++){
			int t=dfs(x,i,u1,d1,l1,r1)+dfs(x,y-i,u2,d2,l2,r2);
			ans2=min(ans2,t);
		}
	}
	return dp[x][y][up][down][left][right]=min(ans1,ans2);
}
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d %d %d",&m,&n,&k);
	printf("%lld",dfs(m,n,1,1,1,1)); 
	return 0;
}
