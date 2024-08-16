#include <bits/stdc++.h>
using namespace std;
const int mtt = 86400+350*3+2*350*180;
struct Bike{
	int arv;
	int last;
};
vector<Bike> t_w;
vector<Bike> t_e;
int ttl;
int dp[350+1][350+1][350+1][2];
//damnic programming :-)
int calc(int drivenWest, int drivenEast, int nt, int lastToEast){
	int &dpv = dp[drivenWest][drivenEast][nt][lastToEast];
	if (dpv == 0x7f7f7f7f){
		if ((lastToEast ? drivenEast : drivenWest) == 0)
			dpv = mtt;//not working
		else{
			const Bike &bikem = (lastToEast ? t_e[drivenEast-1] : t_w[drivenWest-1]);
			if (lastToEast)
				--drivenEast;//east
			else
				--drivenWest;//west
			dpv = mtt;
			for (int dir = 0; dir < 2; ++dir){
				if (nt > 0)
					dpv = min(dpv, calc(drivenWest, drivenEast, nt-1, dir) + (dir == lastToEast ? 3 : ttl));
				int myTime = calc(drivenWest, drivenEast, nt, dir) + (dir == lastToEast ? 3 : ttl);
				if (myTime <= bikem.last)
					dpv = min(dpv, myTime);//well, mt is good, let's get this in here
			}
			if (dpv < mtt)
				dpv = max(bikem.arv, dpv);
			//well, let's see if there is anyone dumped behind
		}
	}
	return dpv;
}
/*
	Code By shanwenxiao on 6th Aug 24
*/
int main(){
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
	int n;
	scanf("%d%d",&ttl,&n);
	for (int i = 0; i < n; ++i){
		string d;
		int mst;
		Bike car;
		cin>>d>>car.arv>>mst;
		car.last=car.arv+mst;
		if (d=="W")
			t_w.push_back(car);//west
		else if(d=="E")
			t_e.push_back(car);//east
	}
	//totalTime = dp[drivenEast][drivenWest][numIrritated][lastToWest=0,lastToEast=1]
	memset(&dp[0][0][0][0], 0x7f7f7f7f, sizeof(dp));//get this dp to be smallest, WA for one
	dp[0][0][0][0] = dp[0][0][0][1] = -3;
	int nt;
	for (nt = 0; nt <= n; ++nt){
		int t = min(
			calc((int)t_w.size(), (int)t_e.size(), nt, 0),
			calc((int)t_w.size(), (int)t_e.size(), nt, 1));
		if (t < mtt)
			break;
	}
	printf("%d",nt);
	return 0;
}
