#include <bits/stdc++.h>
using namespace std;
int mx;
long ans;
long isok(int j){
    long ok=1;
    for(int i=1;i<=j;i++){
        if(i==1&&j==1){
            ok*=2;
            continue;
        }
        ok*=2;
    }
    return ok;
}
int main()
{
    cin>>mx;
    for(int i=1;i<=mx;i++){
        ans+=isok(i);
    }
    cout<<ans;
    return 0;
}
