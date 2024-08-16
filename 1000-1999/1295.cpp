#include <bits/stdc++.h>
using namespace std;
char s[210];
int len;
int main(){
	fgets(s,205,stdin);
	strtok(s,"\r\n");
	len=strlen(s);
	for(int i=0;i<len;i++){
		if(s[i]>='F'&&s[i]<='Z') s[i]-=5;
		else if(s[i]=='E') s[i]='Z';
		else if(s[i]=='D') s[i]='Y';
		else if(s[i]=='C') s[i]='X';
		else if(s[i]=='B') s[i]='W';
		else if(s[i]=='A') s[i]='V';
	}
	for(int i=0;i<len;i++){
		cout<<s[i];
	}
	return 0;
}
