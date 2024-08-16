#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ri register
#define il inline
const int inf=1e9;
const int MAXN=1e5+5e4+5;
const int mod=9875321;
int n,m,M,rt;
struct tnode{
    int dat,val,fa,sz;
    int ch[3];
} t[MAXN];
int p[MAXN];
char s[MAXN];
il int newnode(int val,int fa,int cl,int cr){
    t[++M]=(tnode){val,val,fa,1};
    t[M].ch[0]=cl; t[M].ch[1]=cr;
    return M;
}
il void update(int u){
    if (!u) return;
    t[0].dat=t[0].sz=0;
    int cl=t[u].ch[0],cr=t[u].ch[1];
    int szl=t[cl].sz,szr=t[cr].sz;
    t[u].sz=szl+szr+1;
    t[u].dat=((ll)t[cl].dat*p[szr+1]%mod+(ll)p[szr]*t[u].val%mod+t[cr].dat)%mod;
}
il void rotate(int u){
    int f1=t[u].fa;
    int f2=t[f1].fa;
    int dir1=t[f1].ch[1]==u;
    int dir2=t[f2].ch[1]==f1;
    int sn=t[u].ch[dir1^1];
    t[sn].fa=f1; t[f1].ch[dir1]=sn;
    t[f1].fa=u; t[u].ch[dir1^1]=f1;
    t[u].fa=f2; t[f2].ch[dir2]=u;
    update(f1); update(u); 
}
il void splay(int u,int go){
    if (u==go) return;
    while (t[u].fa!=go){
        int f1=t[u].fa;
        int f2=t[f1].fa;
        int dir1=t[f1].ch[1]==u;
        int dir2=t[f2].ch[1]==f1;
        if (f2==go){
            rotate(u);
            break;
        }
        if (dir1==dir2) rotate(f1);
        else rotate(u);
        rotate(u);
    }
    if (go==0) rt=u;
}
int num(int u,int rk){
    int cl=t[u].ch[0],cr=t[u].ch[1];
    int szl=t[cl].sz,szr=t[cr].sz;
    if (cl==0&&cr==0) return u;
    if (rk<=szl) return num(cl,rk);
    else if (rk>szl+1) return num(cr,rk-szl-1);
    else return u;
}
il void ins(int key,char c){
    int cdat=c-'a'+1;
    if (abs(key)>=inf) cdat=0;
    if (rt==0){
        rt=newnode(cdat,0,0,0);
        return;
    }
    splay(num(rt,key+1),0);
    int u=rt;
    int cl=t[u].ch[0];
    rt=newnode(cdat,0,cl,u);
    t[u].fa=rt; t[cl].fa=rt;
    t[u].ch[0]=0;
    update(u); update(rt);
}
/*int qry(int key){
    splay(num(rt,key+2),0);
//  cout<<__func__<<key<<" "<<(char)(t[rt].val+'a'-1)<<" "<<t[t[rt].ch[0]].dat<<endl;
    return t[t[rt].ch[0]].dat%mod;
}
bool check(int x,int y,int mid){
    int xr=x+mid-1,yr=y+mid-1;
    cout<<x<<" "<<xr<<" "<<y<<" "<<yr<<endl;
    if (xr>n||yr>n) return 0;
//  cout<<qry(xr)<<" "<<qry(x-1)<<endl;
    int ansx=(ll)((qry(xr)-(ll)qry(x-1)*p[mid]%mod)%mod+mod)%mod;
    int ansy=(ll)((qry(yr)-(ll)qry(y-1)*p[mid]%mod)%mod+mod)%mod;
    cout<<ansx<<" "<<ansy<<endl;
    return ansx==ansy;
}*/
il int qry(int l,int r){
    splay(num(rt,l),0);
    splay(num(rt,r+2),rt);
    return t[t[t[rt].ch[1]].ch[0]].dat%mod;
}
il bool check(int x,int y,int mid){
    int xr=x+mid-1,yr=y+mid-1;
    if (xr>n||yr>n) return 0;
    return qry(x,xr)==qry(y,yr);
}
il void solve(int x,int y){
    if (x==y){
        printf("%d\n",n-x+1);
        return;
    }
    int l=0,r=max(n-x+1,n-y+1)+1,mid;
//  cout<<__func__<<" "<<l<<" "<<r<<endl;
    while (l+1<r){
        mid=(l+r)>>1;
        if (check(x,y,mid)) l=mid;
        else r=mid;
    }
    printf("%d\n",l);
}
void prt(int u){
    int cl=t[u].ch[0],cr=t[u].ch[1];
    printf("id:%d c:%d dat:%d fa:%d cl:%d cr:%d\n",u,t[u].val,t[u].dat,t[u].fa,cl,cr);
    if (cl) prt(cl);
//  printf("%c",(char)t[u].val+'a'-1);
    if (cr) prt(cr);
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    p[0]=1;
    for (ri int i=1;i<=105000;i++) p[i]=(ll)p[i-1]*27%mod;
    ins(inf,'a'); ins(-inf,'a');
    for (ri int i=1;i<=n;i++) ins(i,s[i]);
//  prt(rt);cout<<endl;
    scanf("%d",&m);
    for (ri int i=1;i<=m;i++){
        char c=getchar(); while (c!='Q'&&c!='R'&&c!='I') c=getchar();
        int x; scanf("%d",&x);
        if (c=='Q'){
            int y; scanf("%d",&y);
            solve(x,y);
        }
        if (c=='R'){
            char y=getchar(); while (y<'a'||y>'z') y=getchar();
            splay(num(rt,x+1),0);
            t[rt].val=y-'a'+1;
            update(rt);
        }
        if (c=='I'){
            char y=getchar(); while (y<'a'||y>'z') y=getchar();
            ins(x+1,y);
            n++;
        }
//      prt(rt); cout<<endl;
    }
    return 0;
}
