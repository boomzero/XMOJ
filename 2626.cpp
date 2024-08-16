#include <bits/stdc++.h>
using namespace std;
int x,y,a,b,ans,p[10010],q[10010];
int main(){
    cin>>x>>y>>a>>b;
    for(int i=a;i<=x;++i)
        for(int j=b;j<i&&j<=y;++j){
            p[ans]=i;
            q[ans]=j;
            ++ans;
        }
    cout<<ans<<endl;
    for(int i=0;i<ans;++i)
        cout<<p[i]<<" "<<q[i]<<endl;
    return 0;
}
