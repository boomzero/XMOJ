#include <bits/stdc++.h>
using namespace std;
int DAY[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int yy1,mm1,dd1,hh1,mi1,yy2,mm2,dd2,hh2,mi2;
int n,t[5000],ans;
long long minutes;
int main(){
    scanf("%d-%d-%d-%d:%d",&yy1,&mm1,&dd1,&hh1,&mi1);
    scanf("%d-%d-%d-%d:%d",&yy2,&mm2,&dd2,&hh2,&mi2);
    minutes-=hh1*60+mi1; // 回到起点当天的0点整
    minutes+=hh2*60+mi2;
    while(!(yy1==yy2&&mm1==mm2&&dd1==dd2)){
        if(yy1%400==0||yy1%4==0&&yy1%100) DAY[2]=29;
        else DAY[2]=28;
        minutes+=1440;
        ++dd1;
        if(dd1>DAY[mm1]){
            dd1=1;
            ++mm1;
            if(mm1==13){
                mm1=1;
                ++yy1;
            }
        }
    }
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&t[i]);
    sort(t,t+n);
    for(int i=0;i<n;++i){
        minutes-=t[i];
        if(minutes<0) break;
        ++ans;
    }
    printf("%d\n",ans);
    return 0;
}
