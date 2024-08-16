#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],num[1000005],tot,ps0;
long long x;
map<int,bool> mp;
bool judge(int mid){
    int ps=upper_bound(a+1,a+n+1,mid)-a,ch=0;
    long long dis=0,res=0;
    int psmid=upper_bound(num+1,num+tot+1,mid)-num-1;
    ps0=lower_bound(a+1,a+n+1,0)-a-1;
    if(psmid==0) return 1;
    // cout<<mid<<' '<<ps<<' '<<ps0<<' '<<psmid<<endl;
    if(ps-ps0-1+n-ps+1>=mid+1){
        for(int i=psmid;i>=1;i--){
            dis+=a[ps]-num[i];
            ps++;
        }
    }
    else{
        ch=mid+1-(ps-ps0-1+n-ps+1);
        for(int i=1;i<=ch;i++){
            dis+=num[i]-a[ps0];
            ps0--;
        }
        for(int i=psmid;i>ch;i--){
            dis+=a[ps]-num[i];
            ps++;
        }
    }
    // cout<<ch<<' '<<dis<<endl;
    res=dis;
    ps--;
    ch++;
    while(ps0>=1&&ch<=psmid){
        dis-=a[ps]-num[ch];
        // cout<<"ps:"<<ps<<endl;
        ps--;
        dis+=num[ch]-a[ps0];
        // cout<<"ps0:"<<ps0<<endl;
        ps0--;
        // cout<<dis<<endl;
        res=min(res,dis);
        ch++;
    }
    return res<=x;
}
int main(){
    freopen("roar.in","r",stdin);
    freopen("roar.out","w",stdout);
    scanf("%d%lld",&n,&x);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mp[a[i]]=1;
    }
    sort(a+1,a+n+1);
    for(int i=0;i<n;i++)
        if(!mp[i])
            num[++tot]=i;
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(mid==0)
            l=mid+1;
        else if(judge(mid-1))
            l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",r);
    return 0;
}
