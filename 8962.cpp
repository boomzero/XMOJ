#include<bits/stdc++.h>
using namespace std;
inline int Read(){
  	int s = 0 , w = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = (s << 1) + (s << 3) + ch - '0';
		ch = getchar();
	}
	return s * w;
}
const int MAXN = 60 * (5e4 + 50);
int n,k;
int a[MAXN],s[55][55];
int d[MAXN];
bool vis[MAXN];
priority_queue<pair<int,int> >Q;
int head[MAXN],to[MAXN << 1],nxt[MAXN << 1],val[MAXN << 1],tot;
void add(int x,int y,int v){
	to[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	val[tot] = v;
}
int id(int i,int j){
	return i * n + j;
}
void Dijkstra(int s){
	memset(d,127,sizeof(d));
	Q.push(make_pair(0,s));
	d[s] = 0;
	while(!Q.empty()){
		int u = Q.top().second;
		Q.pop();	
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u] ; i ; i = nxt[i]){
			int v = to[i];
			if(d[v] > d[u] + val[i]){
				d[v] = d[u] + val[i];
				Q.push(make_pair(-d[v],v));
			}
		}
 	}
}
int main(){
	freopen("message.in", "r", stdin);
	freopen("message.out", "w", stdout);
	n = Read() , k = Read();
	for(int i = 1 ; i <= n ; i ++) a[i] = Read();
	for(int i = 1 ; i <= k ; i ++){
		for(int j = 1 ;  j <= k ; j ++){
			char ch = getchar();
			while(ch != '0' && ch != '1') ch = getchar();
			s[i][j] = ch - '0';
		}
	}
	for(int i = 1 ; i <= k ; i ++){
		for(int j = 1 ; j + 1 <= n ; j ++){
			add(id(i,j),id(i,j + 1),1);
			add(id(i,j + 1),id(i,j),1);
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= k ; j ++){
			if(s[a[i]][j]) add(i,id(j,i),0);
		}
		add(id(a[i],i),i,0);
	}
	Dijkstra(1);
	if(d[n] < 0x7f7f7f7f) printf("%d\n",d[n]);
	else printf("-1\n");
	return 0;
}

