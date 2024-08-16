#include <bits/stdc++.h>
using namespace std;
int n,t,c,x,ans,m;
int main(){
    cin>>n>>t>>c;
    for(int i=0;i<n;++i){
        cin>>x;
        if(x<=t)
            ++m;
        if(x>t||i==n-1)
            if(m>=c){
                ans+=m-c+1;
            }
        if(x>t)
            m=0;
    }
    cout<<ans;
    return 0;
}
