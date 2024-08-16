#include<iostream>
#include<queue>
using namespace std;
struct ship{
	int time;
	int guo;
};
queue <ship> a;
int b[300001],c;
int main(){
	freopen("port.in","r",stdin);
	freopen("port.out","w",stdout);
	int n;
	int cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int second,Number;
		scanf("%d%d",&second,&Number);
		for(int d=1;d<=Number;d++){
			cin>>c;
			b[c]++;
			if(b[c]==1){
				cnt++;
			}
			ship e;
			e.time=second;
			e.guo=c;
			a.push(e);
		}
		ship e,u;
		e=a.front();
		u=a.back();
		while(u.time-e.time>=86400){
			b[e.guo]--;
			if(b[e.guo]==0){
				cnt--;
			}
			a.pop();
			e=a.front();
		}
		printf("%d\n",cnt);
	}
	return 0;
}
