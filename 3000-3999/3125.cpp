#include <bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &FF){
	T RR=1;FF=0;char CH=getchar();
	for(;!isdigit(CH);CH=getchar())if(CH=='-')RR=-1;
	for(;isdigit(CH);CH=getchar())FF=(FF<<1)+(FF<<3)+(CH^48);
	FF*=RR;
}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x*=-1;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
vector<int>v[100010];
int ji[100010],ou[100010];
void bfw(){
	memset(ji,0x3f,sizeof(ji));
	memset(ou,0x3f,sizeof(ou));
	queue<pair<int,int> >q;
	for(int i=0;i<v[1].size();i++){
		ji[v[1][i]]=1;
		q.push(make_pair(v[1][i],1));
	}
	while(q.size()){
		int x=q.front().first,y=q.front().second;
		for(int i=0;i<v[x].size();i++){
			if(y%2==1){
				if(y+1<ou[v[x][i]]){
					ou[v[x][i]]=y+1;
					q.push(make_pair(v[x][i],y+1));
				}
			}else{
				if(y+1<ji[v[x][i]]){
					ji[v[x][i]]=y+1;
					q.push(make_pair(v[x][i],y+1));
				}
			}
		}
		q.pop();
	}
}
int main(){
	freopen("work.in","r",stdin);
	freopen("work.out","w",stdout);
	int n,m,q;
	read(n);read(m);read(q);
	for(int i=1;i<=m;i++){
		int x,y;
		read(x);read(y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfw();
	while(q--){
		int x,y;
		read(x);read(y);
		if(y%2==0){
			if(ou[x]>y)puts("No");
			else puts("Yes");
		}else{
			if(ji[x]>y)puts("No");
			else puts("Yes");
		}
	}
	return 0;
}
