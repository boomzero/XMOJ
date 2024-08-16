#include <bits/stdc++.h>
using namespace std;
double s=0;
int main(){
    for(int i=1,j=1;i<=1000001;i+=2,j*=-1){
        s+=1.0/i*j;
    }
    s*=4;
    printf("%12.10f",s);
    return 0;
}
