#include <bits/stdc++.h>
using namespace std;
char s[60];
long long len;

int main() {
    cin>>s;
    len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='a'&&s[i]<='z'){
            s[i]-=32;
        }
        else{
            s[i]+=32;
        }
        s[i]+=3;
        if(s[i]>'z'){
            s[i]-=26;
        }else if(s[i]>'Z'&&s[i]<'a'){
            s[i]-=26;
        }
    }
        for(long long i=len-1;i>=0;i--){
            cout<<s[i];
        }
    return 0;
}
