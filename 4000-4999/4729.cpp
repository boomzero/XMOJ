#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar()) f^=(ch=='-');
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return f ? -x : x;
}
#define maxn 100020
int n,a[maxn],blo,bl[maxn],tag[maxn];
vector<int> qwq[1000];
void reset(int x) {
	qwq[x].clear();
	for (int i=(x-1)*blo+1;i<=min(x*blo,n);++i) {
		qwq[x].push_back(a[i]);
	}
	sort(qwq[x].begin(),qwq[x].end());
}
void add(int l,int r,int c) {
	for (int i=l;i<=min(r,bl[l]*blo);++i) {
		a[i]+=c;
	}
	reset(bl[l]);
	if (bl[l]!=bl[r]) {
		for (int i=(bl[r]-1)*blo+1;i<=r;++i) {
			a[i]+=c;
		}
		reset(bl[r]);
	}
	for (int i=bl[l]+1;i<=bl[r]-1;++i) {
		tag[i]+=c;
	}
}
int query(int l,int r,int c) {
	int ans=-2147483600;
	for (int i=l;i<=min(r,bl[l]*blo);++i) {
		int val=a[i]+tag[bl[l]];
		if (val<c) ans=max(ans,val);
	}
	if (bl[l]!=bl[r]) {
		for (int i=(bl[r]-1)*blo+1;i<=r;++i) {
			int val=a[i]+tag[bl[r]];
			if (val<c) ans=max(ans,val);
		}
	}
	for (int i=bl[l]+1;i<=bl[r]-1;++i) {
		int x=c-tag[i];
		if (qwq[i][0]>=x) continue;
		auto iter=lower_bound(qwq[i].begin(),qwq[i].end(),x);
		if (iter==qwq[i].begin()) continue;
		ans=max(ans,*(iter-1)+tag[i]);
 	}
	return ans;
}   
signed main(){
	memset(tag,0,sizeof(tag));
	n=read();
	blo=1000;
	for (int i=1;i<=n;++i) {
		a[i]=read();
		bl[i]=(i-1)/blo+1;
		qwq[bl[i]].push_back(a[i]);
	}
	for (int i=1;i<=bl[n];++i) {
		sort(qwq[i].begin(),qwq[i].end());
	}
	int opt,l,r,c;
	for (int i=1;i<=n;++i) {
		opt=read();
		l=read();
		r=read();
		c=read();
		if (opt==0) {
			add(l,r,c);
		}
		else if (opt==1) {
			int ans=query(l,r,c);
			printf("%d\n",ans==(-2147483600) ? -1 : ans);
		}
	}
	return 0;
}
