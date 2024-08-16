#include <bits/stdc++.h>
using namespace std;
int ans, k;
inline int read(){
	int r=0, k=1;
	char c=getchar();
	for(; c<'0'||c>'9'; c=getchar())
		if(c=='-')
			k=-1;
	for(; c>='0'&&c<='9'; c=getchar())
		r=r*10+c-'0';
	return k*r;
}
void dfs(int n) {
	if(n>k && !((n-k)&1)) {
		int a=(n-k)>>1;
		dfs(a); dfs(n-a);
	}
	else ++ans;
}
int main() {
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int n=read();
	k=read();
	dfs(n);
	printf("%d",ans);
	return 0;
}
//当2|(n-k)时，才能分，否则不能分。
