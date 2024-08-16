#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a,i##_end_=b;i<=i##_end_;++i)
typedef long long ll;
using namespace std;
namespace IO{
	template<typename T>void read(T &_){
		T __=0,mul=1; char ch=getchar();
		while(!isdigit(ch)){
			if(ch=='-')mul=-1;
			ch=getchar();
		}
		while(isdigit(ch))
			__=(__<<1)+(__<<3)+(ch^'0'),ch=getchar();
		_=__*mul;
	}
}
using namespace IO;
const int maxn=2000+10;
int n,m,a[maxn][maxn],b[maxn][maxn],ans;
char s[maxn];
stack<int>stk;
int main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	read(n),read(m);
	if(n==1||m==1)
		return printf("%d\n",n*m),0;
	REP(i,1,n){
		scanf("%s",s+1);
		REP(j,1,m)
			a[i][j]=(s[j]=='#');
	}
	REP(i,1,n-1)
		REP(j,1,m-1){
			int c[2]={0};
			++c[a[i][j]];
			++c[a[i+1][j]];
			++c[a[i][j+1]];
			++c[a[i+1][j+1]];
			b[i][j]=!(c[1]%2);
			if(b[i][j])
				b[i][j]+=b[i-1][j];
		}
	REP(i,1,n-1){
		int las;
		REP(j,1,m-1){
			las=j;
			while(!stk.empty()&&b[i][stk.top()]>=b[i][j]){
				las=stk.top();
				stk.pop();
				if(b[i][las])
					ans=max(ans,(j-las+1)*(b[i][las]+1));
			}
			b[i][las]=b[i][j];
			stk.push(las);
		}
		while(!stk.empty()){
			las=stk.top();
			stk.pop();
			if(b[i][las])
				ans=max(ans,(m-las+1)*(b[i][las]+1));
		}
	}
	printf("%d",max(ans,max(n,m)));
	return 0;
}
