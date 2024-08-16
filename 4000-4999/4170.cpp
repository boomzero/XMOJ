#include <bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int n,d,a[MAXN*2],b[MAXN*2],dist[MAXN*2];
struct cmpA {
    bool operator()(int x,int y) const {
        return b[x]<b[y];
    }
};
struct cmpB {
    bool operator()(int x,int y) const {
        return a[x]<a[y];
    }
};
multiset<int,cmpA> sA;
multiset<int,cmpA>::iterator itA;
multiset<int,cmpB> sB;
multiset<int,cmpB>::iterator itB;
int que[MAXN*2],cur,len;
int main()
{
freopen("set.in","r",stdin);
freopen("set.out","w",stdout);
    scanf("%d%d",&n,&d);
    for (int i=0;i<n*2;++i) {
        scanf("%d%d",&a[i],&b[i]);
        a[i]=-a[i],b[i]=-b[i];
        dist[i]=-1;
    }
    for (int i=0;i<n;++i) {
        if (b[i]==0)
            que[len++]=i,dist[i]=1;
        else
            sA.insert(i);
        if (a[n+i]==0)
            que[len++]=n+i,dist[n+i]=1;
        else
            sB.insert(n+i);
    }
    while (cur<len) {
        int i=que[cur++];
        if (i<n) {
            while(1) {
                itB=sB.lower_bound(i);
                if (itB==sB.end()||a[*itB]>a[i]+d) break;
                dist[*itB]=dist[i]+1;
                que[len++]=*itB;
                sB.erase(itB);
            }
        } else {
            while(1) {
                itA=sA.lower_bound(i);
                if (itA==sA.end()||b[*itA]>b[i]+d) break;
                dist[*itA]=dist[i]+1;
                que[len++]=*itA;
                sA.erase(itA);
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%d\n",dist[i]);
    return 0;
}
