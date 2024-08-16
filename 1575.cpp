#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define N 1010
char s[N];
int p[N][N],f[N];
int mmin(int x,int y){return x<y?x:y;}
int main(){
	int T,l;
	scanf("%d",&T);
	while (T--){
		scanf("%s",s+1);
		l=strlen(s+1);
		memset(p,0,sizeof(p));
		for (int i=1;i<=l;i++)
		{
			int x=0;
			while (i-x>0&&i+x<=l&&s[i-x]==s[i+x]) p[i-x][i+x]=1,x++;
			x=1;
			while (i-x>0&&i+x-1<=l&&s[i-x]==s[i+x-1]) p[i-x][i+x-1]=1,x++;
		}
		f[0]=-1;
		for (int i=1;i<=l;i++)
		{
			f[i]=i-1;
			for (int j=0;j<i;j++)
				if (p[j+1][i]) f[i]=mmin(f[i],f[j]+1);
		}
		printf("%d\n",f[l]);
	}
	return 0;
}
