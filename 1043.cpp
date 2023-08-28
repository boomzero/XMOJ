#include <bits/stdc++.h>
char chart[200][200];
char ans[200][200];
using namespace std;
int main(){
	freopen("mine.in","r",stdin);
	freopen("mine.out","w",stdout);
	int a,b;
	cin>>a>>b;
	string temp1;
	for(int i=1;i<=a;i++){
		cin>>temp1;
		for(int j=0;j<temp1.length();j++){
			chart[i][j+1]=temp1[j];
		}
	}
	int temp=0;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(chart[i][j]=='*'){
				ans[i][j]='*';
			}else{
				temp=0;
				if(i+1<=a&&chart[i+1][j]=='*'){
					temp++;
				}
				if(i-1>0&&chart[i-1][j]=='*'){
					temp++;
				}
				if(j-1>0&&chart[i][j-1]=='*'){
					temp++;
				}
				if(j+1<=b&&chart[i][j+1]=='*'){
					temp++;
				}
				if(i+1<=a&&j+1<=b&&chart[i+1][j+1]=='*'){
					temp++;
				}
				if(i-1>0&&j+1<=b&&chart[i-1][j+1]=='*'){
					temp++;
				}
				if(i+1<=a&&j-1>0&&chart[i+1][j-1]=='*'){
					temp++;
				}
				if(i-1>0&&j-1>0&&chart[i-1][j-1]=='*'){
					temp++;
				}
				ans[i][j]=temp+'0';
				temp=0;
			}
		}
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}

