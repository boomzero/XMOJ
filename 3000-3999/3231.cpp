#include <bits/stdc++.h>
using namespace std;
int n,cnt,j ;
int main(){
    cin>>n;
    for(int i=0;i<10;++i){
        cnt=0,j=n+i;
        while(j){
            cnt+=j%10;
            j/=10;
        }
        if(cnt%4==0){
            cout<<n+i;
            return 0;
        }
    }
    return 0;
}
