#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>s;
    for (int i=s.size()-2;i;i-=2)
        if (s.substr(0,i/2)==s.substr(i/2,i/2)) {
            printf("%d\n",i);
            break;
        }
    return 0;
}
