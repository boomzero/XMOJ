#include <bits/stdc++.h>
using namespace std;
int len,a,b;
char s[110];
int main(){
    cin>>s;
    len=strlen(s);
    for(int i=0;i<len;++i){ 
        if(s[i]=='o'){ 
            ++a;
        } 
        else{ 
            ++b;
        }
	} 
    if(!a||b%a==0){ 
        cout<<"YES";
    } 
    else{ 
        cout<<"NO";
    } 
    return 0;
}
