#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N=50000+5,M=200000+5,V=1000000+5;
int n,m,size,a[N],cnt[V];
struct Query{
    int L,R,bh,ans;
}q[M];
bool cmpmd(Query a,Query b){
    int k1=a.L/size,k2=b.L/size;
    if (k1!=k2)
        return k1<k2;
    return a.R<b.R;
}
bool cmpbh(Query a,Query b){
    return a.bh<b.bh;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        scanf("%d%d",&q[i].L,&q[i].R);
        q[i].bh=i;
    }
    size=sqrt(n)+0.5;
    memset(cnt,0,sizeof cnt);
    sort(q+1,q+m+1,cmpmd);
    for (int i=1,tot=0,L=1,R=0;i<=m;i++){
        while (R<q[i].R){
            R++;
            if (cnt[a[R]]==0)
                tot++;
            cnt[a[R]]++;
        }
        while (L>q[i].L){
            L--;
            if (cnt[a[L]]==0)
                tot++;
            cnt[a[L]]++;
        }
        while (R>q[i].R){
            cnt[a[R]]--;
            if (cnt[a[R]]==0)
                tot--;
            R--;
        }
        while (L<q[i].L){
            cnt[a[L]]--;
            if (cnt[a[L]]==0)
                tot--;
            L++;
        }
        q[i].ans=tot;
    }
    sort(q+1,q+m+1,cmpbh);
    for (int i=1;i<=m;i++)
        printf("%d\n",q[i].ans);
    return 0;
}
