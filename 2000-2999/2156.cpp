#include <bits/stdc++.h>
using namespace std;
int n;
int a1,a2,a3,t1,p1,q1;
int b1,b2,b3,t2,p2,q2;
int p(int x)
{
    if (x==1) return 7;
    return x;
}
void check(int a,int b,int c,int &t,int &x,int &y)
{
    if (a==b&&a==c) {
        t=3; x=p(a); y=0;
        return;
    }
    if (a==b) {
        t=2; x=p(a); y=p(c);
        return;
    }
    if (a==c) {
        t=2; x=p(a); y=p(b);
        return;
    }
    if (b==c) {
        t=2; x=p(b); y=p(a);
        return;
    }
    t=1; x=a+b+c; y=0;
}
void ans(){
        int r;
        if (t1!=t2)
            r=t1-t2;
        else if (p1!=p2)
            r=p1-p2;
        else
            r=q1-q2;
        if (r>0)
            cout<<"XiaoMing"<<endl;
        else if (r<0)
            cout<<"XiaoWang"<<endl;
        else
            cout<<"Draw"<<endl;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a1>>a2>>a3>>b1>>b2>>b3;
        check(a1,a2,a3,t1,p1,q1);
        check(b1,b2,b3,t2,p2,q2);
        ans();
    }
    return 0;
}
