#include<bits/stdc++.h>
using namespace std;
struct win {
    int l,r,t,b;
};
win w1,w2,w3;
int ans;
/*struct是devc++提供的自定义函数，可以包含许多变量 
，可以说是变量的大家庭。
他的成员变量调用方法为“结构体变量名.成员变量名” 
*/ 
void read(win& w)
{
    cin>>w.l>>w.r>>w.t>>w.b;
}//定义一个读入函数
 
int main()
{
    int ans=0;
    read(w1);
    read(w2);
    w3.l=max(w1.l,w2.l);
    w3.r=min(w1.r,w2.r);
    w3.t=max(w1.t,w2.t);
    w3.b=min(w1.b,w2.b);
    if (w3.l<w3.r&&w3.t<w3.b)
        ans=(w3.r-w3.l)*(w3.b-w3.t);
    cout<<ans;
}
 
