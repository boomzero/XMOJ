#include<bits/stdc++.h>
using namespace std;
deque<int>dq;
bool vis[1010]={false};
int m,n,a,dep=0,cnt=0;
int main(){
	freopen("translate.in","r",stdin);
	freopen("translate.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(!vis[a]){
			vis[a]=true;
			cnt++;
			if(dep==m){
				vis[dq[0]]=false;
				dq.pop_front();
				dq.push_back(a);
			}
			else{
				dep++;
				dq.push_back(a);
			}
		}
	}
	cout<<cnt;
	return 0;
}
