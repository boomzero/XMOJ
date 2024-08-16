#include <bits/stdc++.h>
using namespace std;
char a[1000010],b[20];
int lena,lenb,ans,first=1000001;
bool okay=false;
int main(){
	gets(b);
	gets(a);
	lena=strlen(a);
	lenb=strlen(b);
	for(int i=0;i<lenb;i++){
		if(b[i]<='Z') b[i]+=32;
	}
	for(int i=0;i<lena;i++){
		if(a[i]<='Z'&&a[i]!=' ') a[i]+=32;
	}
	lena++;
	a[lena-1]=' ';
//	for(int i=0;i<lena;i++){
//		cout<<a[i];
//	}
//	cout<<endl;
//	cout<<b[0]<<b[1]<<endl;
	if(lena<lenb){
		cout<<"-1";
		return 0;
	}
	for(int i=0;i<lena;i++){
		if(a[i]==b[0]){
			if(i!=0&&a[i-1]!=' ') continue;
			if(a[i+lenb]!=' ') continue;
			int tmp=i;
			for(int j=0;j<lenb;j++){
				if(a[tmp]!=b[j]){
					okay=false;
					break;
				}
				tmp++;
			}
			if(tmp!=i+lenb) continue;
			ans++;
			first=min(i,first);
			i+=lenb-1;
		}
	}
	if(ans==0){
		cout<<-1;
		return 0;
	}
	cout<<ans<<" "<<first;
	return 0;
}
