#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
const int INF = 1e9;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    freopen("hexagon.in","r",stdin);
    freopen("hexagon.out","w",stdout);
    int tt;
    cin>>tt;
    const long double pi=3.141592653589793238462;
    while(tt--){
        vector<long double> X(6),Y(6);
        rep(i,6)
        	cin>>X[i]>>Y[i];
        long double mx=INF,my=INF;
        rep(i,6){
            if(X[i]>0 && Y[i]>0 && Y[i]<my){
                mx=X[i],my=Y[i];
            }
        }
        long double ans=atan2(my,mx)*180/pi;
        if(ans>59) ans-=60;
        cout<<fixed<<setprecision(12)<<ans<<endl;
        // printf(".12lf\n",ans);
    }
	return 0;
}
