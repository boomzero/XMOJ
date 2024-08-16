#include <bits/stdc++.h>
using namespace std;
int n,s[30],nm,sc;
char name[30][30];
int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>name[i]>>s[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]<s[j]){
                swap(s[i],s[j]);
                swap(name[i],name[j]);
            }
            else if(s[i]==s[j]){
                if(strcmp(name[i],name[j])>0){
	                swap(s[i],s[j]);
	                swap(name[i],name[j]);
                }
            }
        }
    }

    for(int k=0;k<n;k++){
    cout<<name[k]<<" "<<s[k]<<endl;
    }
    return 0;
}
