#include<bits/stdc++.h>
using namespace std;
int main(){
    double fx=100;
    double left,middle,right;
    left=1.5;
    right=2.4;
    double x;
    while(fabs(fx)>0.000001){
        middle=(left+right)/2;
        x=middle;
        fx=x*x*x*x*x-15*x*x*x*x+85*x*x*x-225*x*x+274*x-121;
        if(fx<0){
            right=middle;
        }else{
            left=middle;
        }
    }
    printf("%.6lf\n",x);
    return 0;
}
