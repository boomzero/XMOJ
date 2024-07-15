#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("title.in","r",stdin);
    freopen("title.out","w",stdout);
    string in;
    getline(cin,in);
    while (in.find(' ')!=string::npos){
        in.erase(in.find(' '),1);
    }
    while (in.find('\n')!=string::npos){
        in.erase(in.find('\n'),1);
    }
    cout<<in.length()<<endl;
}

