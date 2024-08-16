#include <bits/stdc++.h>
using namespace std;
int n,a[2],b[2],l,r;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>l>>r;
        ++a[l];
        ++b[r];
    }
    cout<<min(a[0],a[1])+min(b[0],b[1]);
    return 0;
}
