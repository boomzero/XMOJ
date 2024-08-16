#include <bits/stdc++.h>
using namespace std;
int n,all,prop[20],upgrade;
int main(){
		freopen("props.in","r",stdin);
		freopen("props.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x1,x2,x3;
		scanf("%d%d%d",&x1,&x2,&x3);
		prop[x1]++,prop[x2]++,prop[x3]++;
		all+=3;
	}
//	for(int i=1;i<=10;i++)
//		cout<<prop[i]<<" ";
//	cout<<endl;;
	for(int i=1;i<=10;i++){
		if(prop[i]>=2){
			upgrade+=prop[i]/2;
			all-=(prop[i]/2)*2;
			prop[i]-=(prop[i]/2)*2;
		}
	}
//	cout<<all<<endl;
	upgrade+=all/4;
	printf("%d",upgrade);
	return 0;
}
