#include<bits/stdc++.h>
using namespace std;
int read(){
    int f=1,sum=0;
    char ch;
    for(ch=getchar();(ch<'0'||ch>'9')&&ch!='-';ch=getchar());
    if(ch=='-')
    {
        f=-1;
        ch=getchar();
    }
    for(;ch>='0'&&ch<='9';ch=getchar())
        sum=(sum<<3)+(sum<<1)+ch-48;
    return sum*f;
}
int c[2010][2010],num[2010][2010],line[2010];
int t,k,m,n; 
int main(){
    t=read();k=read();
    for(int i=0;i<=2000;++i)
        c[i][0]=1;
    for(int i=1;i<=2000;++i){
        for(int j=1;j<=i;++j){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
            c[i][j]%=k;
            if(c[i][j]==0)
                line[j]++;
            num[i][j]=num[i][j-1]+line[j];
        }
    }
    for(int i=1;i<=t;++i){
        n=read();m=read();
        if(m>n)
            m=n;
        cout<<num[n][m]<<endl;
    }
    return 0;
}
