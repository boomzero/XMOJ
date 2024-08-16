#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,root,v[N],lch[N],rch[N];
int calc(int rt,int x)
{
    if (!rt) return -1;
    int ans=v[rt];
    if (rt!=x) {
        int l=calc(lch[rt],x);
        int r=calc(rch[rt],x);
        if (l==-1&&r==-1) return -1;
        if (l>0) ans+=l;
        if (r>0) ans+=r;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&root);
    for (int i=1;i<=n;++i)
        scanf("%d%d%d",&v[i],&lch[i],&rch[i]);
    for (int i=1;i<=n;++i)
        printf("%d\n",calc(root,i));
    return 0;
}
