#include <bits/stdc++.h>
using namespace std;
int a[10110],b,alen;
char s[10010];
void read(int x[],int &xlen)
{
    cin>>s;
    xlen=strlen(s);
    for (int i=0;i<xlen;++i)
		x[xlen-i-1]=s[i]-'0';
}
int main()
{
    read(a,alen);
    cin>>b;
    for (int i=0;i<alen;++i)
        a[i]*=b;
    for (int i=0;i<alen;++i) {
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    while (a[alen]>0) {
        a[alen+1]+=a[alen]/10;
        a[alen]%=10;
        ++alen;
    }
    for (int i=alen-1;i>=0;--i) 
		cout<<a[i];
    cout<<endl;
    return 0;
}
