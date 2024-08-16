#include <bits/stdc++.h>
using namespace std;
int n,x,y,ans,i;
int main(){
    cin>>n;
    for(i=0;i<n;++i){
        cin>>x;
        if(x-y-1<15)
            ans+=x-y;
        else{
            ans+=15;
            break;
        }
        y=x;
    }
    if(i==n)
        ans+=min(90-y,15);
    cout<<ans;
    return 0;
}
