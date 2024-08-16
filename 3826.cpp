#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100010,MAXV=100010;
struct elem {
    ll val,cnt;
} maxv1[MAXV],maxv2[MAXV];
bool cmp(const elem& a,const elem& b) { return a.cnt>b.cnt; }
int n,a[MAXN],ans;
int main() {
    freopen("b.in","r",stdin) ;
    freopen("b.out","w",stdout) ;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<MAXV;++i)
        maxv1[i].val=maxv2[i].val=i;
    for (int i=0;i<n;i+=2)
        ++maxv1[a[i]].cnt;
    for (int i=1;i<n;i+=2)
        ++maxv2[a[i]].cnt;
    sort(maxv1,maxv1+MAXV,cmp);
    sort(maxv2,maxv2+MAXV,cmp);
    if (maxv1[0].val==maxv2[0].val)
        ans=max(maxv1[0].cnt+maxv2[1].cnt,maxv1[1].cnt+maxv2[0].cnt);
    else
        ans=maxv1[0].cnt+maxv2[0].cnt;
    cout<<n-ans<<endl;
    return 0;
}
