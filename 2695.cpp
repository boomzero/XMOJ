#include <bits/stdc++.h>
using namespace std;
int main(){
    for(int i=100;i<1000;++i){
        if(i*(i-1)%1000==0)
            cout<<i<<" ";
    }
    return 0;
}
