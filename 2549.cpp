#include <bits/stdc++.h>
using namespace std;
int n,a[110],x,y;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x;
        for(int j=0;j<x;++j){
            cin>>y;
            ++a[y];
        }
    }
    for(int i=1;i<=100;++i)
        if(a[i]==n)
            cout<<i<<" ";
    return 0;
}
