#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
int n,smallest=1e9,second=1e9;
string secondname;
string one="Bessie",two="Elsie",three="Daisy",four="Gertie",five="Annabelle",six="Maggie",seven="Henrietta";
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		string x; int m;
		cin>>x>>m;
		mp[x]+=m;
	}
	if(mp[one]==mp[two]&&mp[two]==mp[three]&&mp[three]==mp[four]&&mp[four]==mp[five]&&mp[five]==mp[six]&&mp[six]==mp[seven]){
		cout<<"Tie";
		return 0;
	}
	smallest=min(smallest,min(mp[one],min(mp[two],min(mp[three],min(mp[four],min(mp[five],min(mp[six],mp[seven])))))));
//	cout<<"=---=---=---=---=---"<<smallest<<endl<<endl;
	for(int i=smallest+1;;i++){
		int ans=0; string sm="";
		if(mp[one]==i){
			ans++;
			sm+=one;
		}
		if(mp[two]==i){
			ans++;
			sm+=two;
		}
		if(mp[three]==i){
			ans++;
			sm+=three;
		}
		if(mp[four]==i){
			ans++;
			sm+=four;
		}
		if(mp[five]==i){
			ans++;
			sm+=five;
		}
		if(mp[six]==i){
			ans++;
			sm+=six;
		}
		if(mp[seven]==i){
			ans++;
			sm+=seven;
		}
		if(ans>1){
			cout<<"Tie";
			return 0;
		}
		else if(ans==1){
			cout<<sm;
			return 0;
		}
//		cout<<i<<": "<<ans<<" : "<<sm<<endl;
	}
	return 0;
}
