#include <bits/stdc++.h>
using namespace std;
int n,t,r[1010],ans[1010],cnt;
int main(){
    cin>>n>>t;
    for(int i=0;i<n;++i)
        cin>>r[i];
    for(int i=0;i<t;++i){
        int maxn=0,idx=0;
        for(int j=0;j<n;++j)
            if(maxn<r[j]){
                maxn=r[j];
                idx=j;
            }
        ans[cnt]=idx;
        ++cnt;
        // p: 商, q: 余数
        int p=r[idx]/(n-1),q=r[idx]%(n-1);
        for(int j=0;j<n;++j){
            if(j==idx)
                continue;
            r[j]+=p; // 每首歌得到p个分值
            if(q){ // 前q首歌均分余数
                ++r[j];
                --q;
            }
        }
        r[idx]=0;
    }
    for(int i=0;i<cnt;++i)
        cout<<ans[i]+1<<endl;
    return 0;
}
