#include <bits/stdc++.h>
using namespace std;
int i,a;
int sumIt(int n){
    int s=0;
    while(n){
        s+=n%10;
        n/=10;
    }
    return s;
}
int main(){
    for(int i=10000;i<99999;++i){
        a=i*10+6;
        if(sumIt(a)==sumIt(a+6)*6)
            cout<<a<<endl;
    }
    return 0;
}
