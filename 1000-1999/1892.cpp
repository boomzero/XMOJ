#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct Edge{
    int next;
    int to;
    int w;
}Sides[600500];
int head[500000],u,v,ct=0;
int w[300100];
long long sum;
long long mxsum;
void add_Sides(int fr,int t){
    Sides[++ct].next=head[fr];
    Sides[ct].to=t;
    head[fr]=ct;
    return;
}
int lca(int st){
    int i,j;
    int num=0;
    int c[150100];
    long long s1=0;
    int m1=0,m2=0;
    for(j=head[st];j;j=Sides[j].next){
        num++;
        c[num]=w[Sides[j].to];
        s1+=c[num];
    }
    for(i=1;i<=num;i++){
        sum=(sum+(s1-c[i])*c[i])%10007;
        if(c[i]>m1){
            m2=m1;m1=c[i];
        }
        else if(c[i]>m2)m2=c[i];
//        printf("%d: %d %d\n",st,m1,m2);
    }
    if(num)
    	if(m1*m2>mxsum)
    		mxsum=m1*m2;
    if(sum<0)
    	sum+=10007;
    return 0;
}
int main(){
    int i,j;
    int n;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        add_Sides(u,v);
        add_Sides(v,u);
    }
    for(i=1;i<=n;i++)
    	scanf("%d",&w[i]);
    for(i=1;i<=n;i++){
        lca(i);
    }
    cout<<mxsum<<" "<<sum;
    return 0;
}
