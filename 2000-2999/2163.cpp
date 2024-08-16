#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,a=0,b=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        int j=i;
        while(j){
            int x=j%10;
            if(x%2) ++a;
            else    ++b;
            j/=10;
        }
    }
    cout<<a<<" "<<b;
    return 0;
}
