#include<bits/stdc++.h>
using namespace std;
int n,m,c,a[1000010];
int judge(int x){
    int ans=1,cnt=0,p=1;
    for(int i=1;i<=n;i++){
        if((a[i]-a[p])<=x&&cnt+1<=c){
            cnt++;
        }
        else{
            ans++;
            cnt=1;
            p=i;
        }
    }
    if(ans<=m){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=0,r=1e9,ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(judge(mid)){
            r=mid-1;
            ans=mid;
        }
        else{
            l=mid+1;
        }
    }
    printf("%d",ans);
}
