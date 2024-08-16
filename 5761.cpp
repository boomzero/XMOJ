#include <bits/stdc++.h>
#define ll __int128
using namespace std;
ll f[1010];
int n, m;
int print(ll x) {
    if (x==0)
        return putchar(48) + putchar(10);
    if (x>=10)
        print(x/10);
    return putchar(x % 10 + 48);
}
int main() {
    scanf("%d%d",&m,&n);
//  clock_t start,end;
//  start=clock();
    f[0]=1;
    for(int i=1;i<=n;++i)
        for(int j=i;j<=m;++j)
            f[j]+=f[j-i];
    print(f[m]);
//  end=clock();
//  printf("time= %fs",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
