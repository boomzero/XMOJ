#include <iostream>
//#include <cstring>
using namespace std;
int val[1005]={0};
//bool used[1005][1005]={false};
bool found[1005]={false};
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    //memset(used,false,sizeof(used));
    int n=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            //if(used[i][j])continue;
            for(int k=1;k<=n;k++){
                if(val[k]==(val[i]+val[j])&&k!=i&&k!=j){
                    ans++;
                    found[k]=true;
                    //cout<<"Match found: "<<val[i]<<" + "<<val[j]<<" = "<<val[k]<<" i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
                    //cout<<"ans is now "<<ans<<endl;
                    //used[i][j]=true;
                    //used[j][i]=true;
                }
            }
        }
    }
    //cout<<ans/2<<endl;
    int an=0;
    for (int i = 1; i <= n; ++i) {
        if (found[i]) an++;
    }
    cout<<an<<endl;
    return 0;
}
