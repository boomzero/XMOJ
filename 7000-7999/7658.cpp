#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void up(int &x,const int &y){
	if(x<y)
		x=y;
}
int gcd(int a,int b){
	return !a?b:gcd(b%a,a);
}
int p[11000000],pri,mp[10000010];
bool v[10000010];
int n,m;
int b[11000000];
int ti[10000010],s[10000010],num[10000010],ans,nowi,re1,re2;
void upd(const int x,const int k){
    if(ti[x]!=nowi)
    	ti[x]=nowi,num[x]=s[x]=0;
    num[x]++,s[x]=gcd(s[x],k);
    if(num[x]>num[ans])
    	ans=x;
    else if(num[x]==num[ans]&&s[x]>s[ans])
    	ans=x;
}
void divide(int x){
    int tmp=x;
    while(x>1){
        int pp=mp[x];
        while(mp[x]==pp) x/=pp;
        upd(pp,tmp);
    }
}
template <typename T> void read(T &a){
	a=0; int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if (ch=='-') f=-1; ch=getchar(); }
	do{ a=a*10+ch-'0'; ch=getchar(); } while('0'<=ch&&ch<='9');
	a*=f;
}
inline void write(int x){
	if(!x) putchar('0');
	char f[200];
	int tmp=x>0?x:-x;
	if(x<0) putchar('-');
	int cnt=0;
	while(tmp>0){
		f[cnt++]=tmp%10+'0';
		tmp/=10;
	}
	while(cnt>0) putchar(f[--cnt]);
}
int main(){
    for(int i=2;i<10000010;i++){
        if(!v[i]) p[++pri]=i,mp[i]=i;
        for(int j=1,k=p[j]*i;j<=pri;j++,k=p[j]*i){
            if(k>=10000010) break;
            v[k]=true; mp[k]=p[j];
            if(i%p[j]==0) break;
        }
    }
    read(n);
    for(int i=1;i<=n;i++)
    	read(b[i]);
    for(nowi=1;nowi<=10;nowi++){
        int i=rand()%n+1,tc=0;
        num[ans=0]=0;
        for(int j=1;j<=n;j++){
            int k=abs(b[i]-b[j]);
            if(!k)
            	tc++;
            divide(k);
        }
        num[ans]+=tc;
        if(num[ans]>re1)
        	re1=num[ans],re2=s[ans];
        else if(num[ans]==re1&&s[ans]>re2)
        	re2=s[ans];
    }
    write(re1),printf(" "),write(re2);
    return 0;
}
