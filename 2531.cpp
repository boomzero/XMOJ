#include <bits/stdc++.h>
using namespace std;
int n,m,i,x,mx,p;
int main(){
    cin>>n>>m;
    for(i=1;i<=n;++i){
        cin>>x;
        x=(x+m-1)/m;
        if(x>=mx){
            mx=x;
            p=i;
        }
    }
    cout<<p;
    return 0;
}
