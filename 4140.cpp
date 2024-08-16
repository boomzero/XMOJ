#include <bits/stdc++.h>
using namespace std;
int n,x,maxx;
char s[110];
int main() {
    scanf("%d%s",&n,s);
    for (int i=0;i<n;++i) {
        if (s[i]=='D') --x;
        else ++x;
         maxx=max(maxx,x);
    }
    printf("%d\n", maxx);
    return 0;
}
