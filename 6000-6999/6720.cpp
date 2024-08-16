#include <bits/stdc++.h>
using namespace std;
inline int gi(){
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return f * x;
}
int n,m,mm,dis[1003],ans,u,v,fa[1003],deep[1003],r[1003];
vector <int> w[1003];
int main(){
	n = gi();
	fa[1] = 1;
	for (int i = 2; i <= n; i++){
		int x = gi();
		fa[i]=x,dis[i]=dis[x]+1,w[x].push_back(i);
	}
	for (int i = 1; i <= n; i++){
		int k = 0, mk = -1;
		for(int j = 1; j <= n; j++){
			if(!r[j]&&dis[j]>mk)
				k=j,mk=dis[j];
		}
		if(k == 0){
			printf("%d\n", i - 1);
			return 0;
		}
		m = fa[fa[k]], r[m] = 1, r[fa[m]] = 1, r[fa[fa[m]]] = 1;
		for (int j = 0; j < w[m].size(); j++){
			u = w[m][j], r[u] = 1;
			for (int l = 0; l < w[u].size(); l++){
				r[w[u][l]] = 1;
			}
		}
		mm = fa[m];
		for (int j = 0; j < w[mm].size(); j++){
			r[w[mm][j]] = 1;
		}
	}
	return 0;
}
