#include <bits/stdc++.h>
using namespace std;
int n,maxans;
string s;
char amax;
int a[130];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	cin>>s;
	for(int i=0;i<n;i++){
		a[s[i]]++;
//		cout<<a[s[i]]<<" "<<s[i]<<" int:"<<(int)s[i]<<endl;
	}
//	cout<<"----"<<endl;
	amax='{';
	for(int i=97;i<=122;i++){
//		cout<<i<<" "<<(char)i<<" "<<a[i]<<" "<<maxans<<" "<<(char)i<<" "<<(int)amax;
		if(a[i]!=0&&a[i]>maxans){
			maxans=a[i],amax=(char)i;
//			cout<<maxans<<" "<<a[i]<<" "<<amax<<" "<<(char)('a'+amax);
		}
		else if(a[i]!=0&&a[i]==maxans&&i<(int)amax){
			maxans=a[i],amax=(char)i;
		}
//		cout<<endl;
	}
	cout<</*(char)*/amax<<endl<<maxans;
	return 0;
}
