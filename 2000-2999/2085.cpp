#include <bits/stdc++.h>
using namespace std;
int n,m,k,f[2000005],cnt;
struct Node{
	int from,to;
}node[2000005];
inline int rd(){
	int ret=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=(ret<<1)+(ret<<3)+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	freopen("recruit.in","r",stdin);
	freopen("recruit.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=m;i++)
		node[i].from=rd(),node[i].to=rd();
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		if(node[i].from>k&&node[i].to>k){
			int fx=find(node[i].from),fy=find(node[i].to);
			if(fx!=fy)
				f[fx]=fy;
			cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		if(node[i].from<=k||node[i].to<=k){
			int fx=find(node[i].from),fy=find(node[i].to);
			if(fx!=fy)
				f[fx]=fy,cnt++;
		}
	}
	printf("%d",m-cnt);
}
