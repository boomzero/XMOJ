#include <queue>
#include <cstdio>
#include <cstring>
#include <utility>
#define N 20010
#define M 400010
using namespace std;
typedef pair<int , int> pr;
priority_queue<pr> q;
int head[N] , to[M] , len[M] , nxt[M] , cnt , dis[22][N] , vis[N] , lim[N] , f[1 << 20][21];
void add(int x , int y , int z)
{
	to[++cnt] = y , len[cnt] = z , nxt[cnt] = head[x] , head[x] = cnt;
}
void dijkstra(int s)
{
	int i , x;
	memset(dis[s] , 0x3f , sizeof(dis[s])) , memset(vis , 0 , sizeof(vis));
	dis[s][s] = 0 , q.push(pr(0 , s));
	while(!q.empty())
	{
		x = q.top().second , q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(i = head[x] ; i ; i = nxt[i])
			if(dis[s][to[i]] > dis[s][x] + len[i])
				dis[s][to[i]] = dis[s][x] + len[i] , q.push(pr(-dis[s][to[i]] , to[i]));
	}
}
int main()
{
	int n , m , d , p , i , j , k , x , y , z , ans = 1 << 30;
	scanf("%d%d%d" , &n , &m , &d);
	for(i = 1 ; i <= m ; i ++ ) scanf("%d%d%d" , &x , &y , &z) , add(x , y , z) , add(y , x , z);
	for(i = 1 ; i <= d + 1 ; i ++ ) dijkstra(i);
	scanf("%d" , &p);
	for(i = 1 ; i <= p ; i ++ ) scanf("%d%d" , &x , &y) , lim[y - 1] |= (1 << (x - 2));
	if(!d)
	{
		printf("%d\n" , dis[1][n]);
		return 0;
	}
	memset(f , 0x3f , sizeof(f));
	for(i = 1 ; i <= d ; i ++ )
		if(!lim[i])
			f[1 << (i - 1)][i] = dis[1][i + 1];
	for(i = 1 ; i < 1 << d ; i ++ )
		for(j = 1 ; j <= d ; j ++ )
			if(i & (1 << (j - 1)))
				for(k = 1 ; k <= d ; k ++ )
					if(!(i & (1 << (k - 1))) && !(~i & lim[k]))
						f[i | (1 << (k - 1))][k] = min(f[i | (1 << (k - 1))][k] , f[i][j] + dis[j + 1][k + 1]);
	for(i = 1 ; i <= d ; i ++ ) ans = min(ans , f[(1 << d) - 1][i] + dis[i + 1][n]);
	printf("%d\n" , ans);
	return 0;
}
