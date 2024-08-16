#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,D,L,a[50005],Ans;
bool check(int i){
    int Now=0,cnt=0;
    for(;i<=n;i++)
    if(a[i]-D*Now>=L){
        cnt++;
        if(cnt==m) cnt=0,Now++;
    }else return 0;
    return 1;
}
int main(){
    scanf("%d%d%d%d",&n,&m,&D,&L);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int L=0,R=n,mid=(R+L)>>1;L<=R;mid=(R+L)>>1)
    if(check(mid)) Ans=mid,R=mid-1;else L=mid+1;
    printf("%d\n",n-Ans+1);
    return 0;
}
