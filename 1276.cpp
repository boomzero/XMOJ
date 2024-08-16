#include<bits/stdc++.h>
using namespace std;
struct Square {
    long long l,r,t,w,h,s;
} s[10010];
int R,n;
long long delta(int mid)
{
    long long sum1=0,sum2=0;
    for(int i=0;i<n;i++) {
        if(s[i].r<=mid) sum1+=s[i].s;
        else if(s[i].l>=mid) sum2+=s[i].s;
        else {
            sum1+=s[i].h*(mid-s[i].l);
            sum2+=s[i].h*(s[i].r-mid);
        }
    }
    return sum1-sum2;
}
int main()
{
    cin>>R>>n;
    for (int i=0;i<n;++i) {
        cin>>s[i].l>>s[i].t>>s[i].w>>s[i].h;
        s[i].s=s[i].w*s[i].h;
        s[i].r=s[i].l+s[i].w;
    }
    int l=0,r=R,mid,ans;
    long long v;
    while (l<=r) {
        mid=(l+r)/2;
        if (delta(mid)>0) r=mid-1;
        else l=mid+1;
    }
    if (delta(l-1)<0) {
        v=delta(l);
        r=R;
        while (l<=r) {
            mid=(l+r)/2;
            if (delta(mid)<=v) l=mid+1;
            else r=mid-1;
        }
    }
    cout<<l-1<<endl;
    return 0;
}
