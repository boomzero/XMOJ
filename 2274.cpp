#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,root,lch[N],rch[N];
void pre(int rt,bool &first)
{
    if (!first) printf(" ");
    printf("%d",rt);
    first=false;
    if (lch[rt]) pre(lch[rt],first);
    if (rch[rt]) pre(rch[rt],first);
}
void mid(int rt,bool &first)
{
    if (lch[rt]) mid(lch[rt],first);
    if (!first) printf(" ");
    printf("%d",rt);
    first=false;
    if (rch[rt]) mid(rch[rt],first);
}
void post(int rt,bool &first)
{
    if (lch[rt]) post(lch[rt],first);
    if (rch[rt]) post(rch[rt],first);
    if (!first) printf(" ");
    printf("%d",rt);
    first=false;
}
int main()
{
    scanf("%d%d",&n,&root);
    for (int i=1;i<=n;++i)
        scanf("%d%d",&lch[i],&rch[i]);
    bool first=true;
    pre(root,first);
	printf("\n");
    mid(root,first=true);
	printf("\n");
    post(root,first=true);
	printf("\n");
    return 0;
}
