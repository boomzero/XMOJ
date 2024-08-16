#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#define INF 1000000000
using namespace std;
int n,m,ans;
char ch[1005];
bitset<1005>a[2005];
void Gauss(){
    int now=0;
    for(int i=1;i<=n;i++){
        int j=now+1;
        while(!a[j][i]&&j<=m)
        	j++;
        if(j==m+1){
        	ans=-1;
        	return;
        }
        else
        	ans=max(ans,j);
        now++;
        swap(a[j],a[now]);
        for(int k=1;k<=m;k++)
            if(k!=now&&a[k][i])
            	a[k]^=a[now];
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%s",ch+1);
        for(int j=1;j<=n;j++)
        	a[i][j]=ch[j]-'0';
        scanf("%s",ch+1);
        a[i][n+1]=ch[1]-'0';
    }
    Gauss();
    if(ans==-1)
    	puts("Cannot Determine");
    else {
        printf("%d\n",ans);
        for(int i=1;i<=n;i++){
            if(a[i][n+1])
            	puts("?y7M#");
            else
            	puts("Earth");
        }
    }
    return 0;
}
