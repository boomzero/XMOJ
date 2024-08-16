#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,v[N],lc[N],rs[N],root;
void w(int x,bool first)
{
    if (!first) printf(" ");
    printf("%d",x);
    int c=lc[x];
    while (c) {
        w(c,false);
        c=rs[c];
    }
}
int main()
{
    scanf("%d%d",&n,&root);
    for (int i=1;i<=n;++i)
        scanf("%d%d%d",&v[i],&lc[i],&rs[i]);
    int k,x,y;
    scanf("%d",&k);
    while (k--) {
        scanf("%d",&x);
        w(x,true),printf("\n");
    }
    return 0;
}
