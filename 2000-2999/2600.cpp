#include <bits/stdc++.h>
using namespace std;
int t,n,k,a[210],c,ans;
int nearest(int j){
    int minn=200;
    for(int p=0;p<k;++p)
        minn=min(abs(j-a[p]),minn);
    return minn;
}
int main(){
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>n>>k;
        for(int j=0;j<k;++j)
            cin>>a[j];
        ans=0;
        for(int j=1;j<=n;++j)
            ans=max(nearest(j),ans);
        cout<<ans+1<<endl;;
    }
    return 0;
}
