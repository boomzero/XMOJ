#include <bits/stdc++.h>
using namespace std;
int a[128],p,q,p0,q0,s;
char pc,qc;
bool cw,ccw;
int main(){
    a['v']=0;
	a['<']=1;
	a['^']=2;
	a['>']=3;
    cin>>pc>>qc>>s;
    p0=a[pc];
	q0=a[qc];
	s%=4;
    if((p0+s)%4==q0){
        cw=true;
    }
    if((p0+3*s)%4==q0)
        ccw=true;
    if(cw==true&&ccw==true)
        cout<<"undefined";
    else
	{
        if(cw==true){
            cout<<"cw";
    	}
        else{
            cout<<"ccw";
        }
    }
    return 0;
}
