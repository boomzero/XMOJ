#include<bits/stdc++.h>
using namespace std;
int n,h,last,sum,i;
int main(){
    scanf("%d",&n);
    h=last=0;sum=1;
    int a=-1;
    scanf("%d",&h);
    last=h;
    for(i=2;i<=n;i++){
        scanf("%d",&h);
        if(h>last && a!=1){
            a=1;
            sum++;
        }
        if(h<last && a!=0){
            a=0;
            sum++;
        }
        last=h;
    }
    printf("%d\n",sum);
    return 0;
}
