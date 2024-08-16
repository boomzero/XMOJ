#include <bits/stdc++.h>
using namespace std;
int n,x=1,y=2,z=3,w;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>w;
        if(w==x)
            swap(y,z);
        else if(w==y)
            swap(x,z);
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
