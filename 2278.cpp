#include <bits/stdc++.h>
using namespace std;
int n,root;
int v[110],lch[110],rch[110],ans[110];
void calculate(int rt,int dep)
{
    ans[rt]=dep;
    if (lch[rt])
        calculate(lch[rt],dep+1);
    if (rch[rt])
        calculate(rch[rt],dep+1);
}
int main()
{
	cin>>n>>root;
    for (int i=1;i<=n;++i)
    cin>>lch[i]>>rch[i];
    calculate(root,1);
    for (int i=1;i<=n;++i)
		cout<<ans[i]<<endl;
    return 0;
}
