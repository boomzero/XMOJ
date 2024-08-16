#include <bits/stdc++.h>
using namespace std;
int a[10010],b[10010],c[20010],alen,blen,clen;
char s[10010];
void read(int x[],int &xlen)
{
    cin>>s;
    xlen=strlen(s);
    for (int i=0;i<xlen;++i) x[xlen-i-1]=s[i]-'0';
}
int main()
{
    read(a,alen);
    read(b,blen);
    clen=alen+blen-1;
    for (int i=0;i<alen;++i){
        for (int j=0;j<blen;++j){
            c[i+j]=c[i+j]+a[i]*b[j];
        }
    }
    for (int i=0;i<clen;++i) {
        c[i+1]=c[i+1]+c[i]/10;
        c[i]=c[i]%10;
    }
    while (c[clen]>0) {
        c[clen+1]=c[clen+1]+c[clen]/10;
        c[clen]=c[clen]%10;
        ++clen;
    }
    for (int i=clen-1;i>=0;--i)
		cout<<c[i];
    return 0;
}
