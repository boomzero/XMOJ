#include <bits/stdc++.h>
using namespace std;
int n,x,a[110],mi,mx;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        ++a[x];
    }
    for(int i=1;i<=100;++i)
        if(a[i]>mx){
            mi=i;
            mx=a[i];
        }
    cout<<mi<<" "<<mx;
    return 0;
}
