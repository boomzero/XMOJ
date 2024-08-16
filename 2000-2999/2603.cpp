#include <bits/stdc++.h>
using namespace std;
int n,x,a[5010],ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        if(x>n||a[x])
            ++ans;
        else
            a[x]=1;
    }
    cout<<ans;
    return 0;
}
