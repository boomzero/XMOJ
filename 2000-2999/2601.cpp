#include <bits/stdc++.h>
using namespace std;
int n,k,x,ans;
bool judge(int x,int k){
    int a[10]={0};
    while(x!=0){
        a[x%10]=1;
        x/=10;
    }
    for(int i=0;i<=k;++i){
        if(a[i]==0)
        {
            return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>x;
        if(judge(x,k)==true)
            ++ans;
    }
    cout<<ans;
    return 0;
}
