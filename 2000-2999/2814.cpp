#include <bits/stdc++.h>
using namespace std;
const int N=50005,M=2000005;
int n,m,Qcnt=0,Ocnt=0;
int c[N],dc[N],k[N];
int tax[M],tot=0;
struct Query{
    int L,R,id,ans;
    Query(){}
    Query(int _L,int _R,int _id){
        L=_L,R=_R,id=_id;
    }
}Q[N];
struct Operation{
    int x,v1,v2,id;
    Operation(){}
    Operation(int _x,int _v1,int _v2,int _id){
        x=_x,v1=_v1,v2=_v2,id=_id;
    }
}O[N];
bool cmp(Query a,Query b){
    if (k[a.L]!=k[b.L])
        return k[a.L]<k[b.L];
    if (k[a.R]!=k[b.R])
        return k[a.R]<k[b.R];
    return a.id<b.id;
}
bool cmpid(Query a,Query b){
    return a.id<b.id;
}
int L=1,R=0,t=0;
void update(int t){
    int x=O[t].v1,y=O[t].v2,id=O[t].x;
    if (c[id]!=x)
        swap(x,y);
    if (L<=id&&id<=R){
        tot-=(--tax[x])==0;
        tot+=(tax[y]++)==0;
    }
    c[id]=y;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&c[i]),dc[i]=c[i];
    for (int i=1;i<=m;i++){
        char ch[2];
        int x,y;
        scanf("%s%d%d",ch,&x,&y);
        if (ch[0]=='Q')
            Q[++Qcnt]=Query(min(x,y),max(x,y),i);
        else {
            O[++Ocnt]=Operation(x,y,dc[x],i);
            dc[x]=y;
        }
    }
    for (int i=1;i<=n;i++)
        k[i]=(i-1)/400;
    sort(Q+1,Q+Qcnt+1,cmp);
    memset(tax,0,sizeof tax);
    O[0].id=0,O[Ocnt+1].id=m+1;
    for (int i=1;i<=Qcnt;i++){
        while (L<Q[i].L)
            tot-=(--tax[c[L++]])==0;
        while (L>Q[i].L)
            tot+=(tax[c[--L]]++)==0;
        while (R<Q[i].R)
            tot+=(tax[c[++R]]++)==0;
        while (R>Q[i].R)
            tot-=(--tax[c[R--]])==0;
        while (O[t+1].id<Q[i].id)
            update(++t);
        while (O[t].id>Q[i].id)
            update(t--);
        Q[i].ans=tot;
    }
    sort(Q+1,Q+Qcnt+1,cmpid);
    for (int i=1;i<=Qcnt;i++)
        printf("%d\n",Q[i].ans);
    return 0;
}
