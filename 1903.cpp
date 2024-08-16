#include <bits/stdc++.h>
using namespace std;
int minn,maxn;//minn是最小进价,maxn是最大利润
int ans,temp;
struct apple {
    int val,pos;
    bool operator < (const apple& a) const {
        return val < a.val;
    }
}p[100010];
int n,t,a[100010];
int main()
{
    cin>>n>>t;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        p[i].val=a[i];
        p[i].pos=i;
    }
    sort(p,p+n);
    minn=a[0];
    for(int i=1;i<n;i++) {
        minn=min(minn,a[i]);
        maxn=max(maxn,a[i]-minn);
    }
    for(int i=0;i<n;i++) {
        temp=lower_bound(p,p+n,(apple){a[i]-maxn})-p;
		//上面的写于2021/06/06 16:49:38
        if(p[temp].val==a[i]-maxn&&p[temp].pos<i){
        	ans+=1;
        }
    }
    cout<<ans;
    return 0;
}
