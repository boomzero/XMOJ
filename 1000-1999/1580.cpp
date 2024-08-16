#include <bits/stdc++.h>
using namespace std;
char s[110];
int a[110],b[110],c[110],la,lb,lc,fa,fb,fc;
void read(int x[],int &n,int &f){
    cin>>s;
    n=strlen(s);
    for(int i=0,j=n;i<n;++i,--j)
        if(s[i]=='-')
            f=1;
        else
            x[j]=s[i]-'0';
    n-=f;
}
bool large(){
    if(la!=lb)
        return la>lb;
    for(int i=la;i>=1;--i)
        if(a[i]!=b[i])
            return a[i]>b[i];
    return true;
}
void plus1(){
    lc=max(la,lb);
    for(int i=1;i<=lc;++i){
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if(c[lc+1])
        ++lc;
}
void minus1(int x[],int lx,int y[],int ly){
    lc=lx;
    for(int i=1;i<=lc;++i){
        c[i]=x[i]-y[i];
        if(c[i]<0){
            --x[i+1];
            c[i]+=10;
        }
    }
    while(lc>1&&c[lc]==0) --lc;
}
int main(){
    read(a,la,fa);
    read(b,lb,fb);
    if(fa==fb){
        plus1();
        fc=fa;
    }else if(large()){
        minus1(a,la,b,lb);
        fc=fa;
    }else{
        minus1(b,lb,a,la);
        fc=fb;
    }
    if(lc==1&&c[1]==0) fc=0;
    if(fc) cout<<"-";
    for(int i=lc;i>=1;--i) cout<<c[i];
    return 0;
}
