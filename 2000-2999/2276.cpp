#include <bits/stdc++.h>
using namespace std;
int n,root;
int v[110],lch[110],rch[110],ans[110];
void calc(int rt)
{
    if (!rt)
        return;
    calc(lch[rt]);
    calc(rch[rt]);
    ans[rt]=v[rt]+ans[lch[rt]]+ans[rch[rt]];
}
int main()
{
    cin>>n>>root;
    for (int i=1;i<=n;++i)
        cin>>v[i]>>lch[i]>>rch[i];
    calc(root);
    for (int i=1;i<=n;++i)
    	cout<<ans[i]<<endl;
    return 0;
}
