#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
char str[3][105];
bool err,used[128];
int cnt=0;
map<char,char>mp;
int main(){
	scanf("%s%s%s",str[0],str[1],str[2]);
	for(int i=0;str[1][i]!='\0';i++)
		if(!mp.count(str[0][i])&&!used[(int)str[1][i]])
			used[(int)str[1][i]]=true,mp[str[0][i]]=str[1][i],cnt++;
	else if(mp[str[0][i]]!=str[1][i])
		err=true;
	if(err||cnt<26) printf("Failed");
	else{
		for(int i=0;str[2][i]!='\0';i++) putchar(mp[str[2][i]]);
	}
	return 0;
}
