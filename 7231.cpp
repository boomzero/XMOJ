#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define inf 1000000000
#define maxn 100000
#define maxm 500+100
#define eps 1e-10
#define ll long long
#define pa pair<int,int>
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define mod 1000000007
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
char s[10]="luvletter";
int f[100];
int main(){
    int cs=read();
    while(cs--){
       char ch=' ';int now=0,ans=0;
       while((ch<='z'&&ch>='a')||(ch==' ')){
           ch=getchar();
           if(ch==s[now]){now++;if(now==9)now=0,ans++;}
       }
       printf("%d\n",ans);
    }
    return 0;
}
