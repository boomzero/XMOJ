#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int T, p, a, b, c, d;
int quick_pow(int a, int b){
	int res = 1;
	for(;b;b >>= 1, a = (LL)a * a % p)
		if(b & 1) res = (LL)res * a % p;
	return res;
}
bool chk(int x, int l, int r){
	if(l > r) return r < x && x <= l;
	return x <= l || x > r; 
}
char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
int main(){
	p=read(),T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read();
		int s=(a+b)%p;
		if(s!=(c+d)%p)
			puts("-1");
		else{
			int inv=quick_pow(s,p-2),k=0;
			a=(LL)a*inv%p;c=(LL)c*inv%p;
			for(;(1 << k)<p&&chk(c,(LL(a?:p)-1<<k)%p,(LL(a)<<k)%p);k++);
				printf("%d\n", k);
		}
	}
	return 0;
}
