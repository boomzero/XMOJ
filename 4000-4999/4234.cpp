#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
vector<int> v[100010],u[100010];
int ord[100010],in[100010],oc[100010];
bool tpsort(){
	priority_queue<int,vector<int>,greater<int> > q;
	cnt=0;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(q.size()){
		int h=q.top();
		ord[cnt++]=h;
		q.pop();
		for(int i=0;i<u[h].size();i++)
			if(--in[u[h][i]]==0)
				q.push(u[h][i]);
	}
	if(cnt==n)
		return 1;
	else
		return 0;
}
void add(int p){
	for(int i=1;i<v[p].size();i++){
		u[v[p][i-1]].push_back(v[p][i]);
		in[v[p][i]]++;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int l=0,r=m;
	for(int i=0,x,y;i<m;i++){
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			scanf("%d",&y);
			v[i].push_back(y);
		}
		if(i<m/2)
			add(i);
	}
	while(l<=r){
		//		cout<<l<<" "<<r<<endl;
		int mid=(l+r)/2;
		for(int i=0;i<mid;i++)
			add(i);
		if(tpsort()){
			l=mid+1;
			memcpy(oc,ord,sizeof(oc));
		}
		else
			r=mid-1;
		for(int i=1;i<=n;i++)
			u[i].clear();
		memset(in,0,sizeof(in));
	}
	//	cout<<r<<"\n";
	for(int i=0;i<n;i++)
		cout<<oc[i]<<" ";
}
