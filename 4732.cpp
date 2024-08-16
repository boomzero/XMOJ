#include <bits/stdc++.h>
#define int long long
#define bpi bk[pt[ii+1]]
using namespace std;
const int N=1e5+10;
int n,a[N],t,blks,pt[1000];
vector<int> bk[1000];
void update(int l,int r) {
	int blk=-1,ii=-1;
	for (int i=1; i<=blks; i++) {
		if (l<=bk[pt[i]].size()) {
			blk=pt[i],ii=i;
			break;
		}
		l-=bk[pt[i]].size();
	}
	bk[blk].push_back(0);
	int sz=bk[blk].size()-1;
	for (int i=sz; i>=l; i--)
		bk[blk][i]=bk[blk][i-1];
	bk[blk][l-1]=r;
	if (bk[blk].size()>(t<<1)) {
		blks++;
		for (int i=t; i<bk[blk].size(); i++)
			bk[blks].push_back(bk[blk][i]);
		bk[blk].erase(bk[blk].begin()+t,bk[blk].end());
		for (int i=blks; i>ii+1; i--)
			pt[i]=pt[i-1];
		pt[ii+1]=blks;
	}
}
int query(int l) {
	int blk=-1;
	for (int i=1; i<=blks; i++) {
		if (l<=bk[pt[i]].size()) {
			blk=i;
			break;
		}
		l-=bk[pt[i]].size();
	}
	return bk[pt[blk]][l-1];
}
signed main() {
	scanf("%lld",&n);
	for (int i=1; i<=n; i++)
		scanf("%lld",a+i);
	t=sqrt(n),blks=1;
	for (int i=1; i<=n; i++) {
		if (bk[blks].size()==t) blks++;
		bk[blks].push_back(a[i]);
		pt[blks]=blks;
	}
	for (int i=0,op,l,r,c; i<n; i++) {
		scanf("%lld%lld%lld%lld",&op,&l,&r,&c);
		if (!op) update(l,r);
		else printf("%lld\n",query(r));
	}
	return 0;
}
