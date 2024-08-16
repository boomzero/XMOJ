#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 10000007;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int maxn = 50010;
int N, W, x[maxn], y[maxn];
int main(){
	freopen("skyline.in","r",stdin);
	freopen("skyline.out","w",stdout);
	scanf("%d%d", &N, &W);
	for(int i = 0; i < N; i++)
		scanf("%d%d", &x[i], &y[i]);
	y[N] = 0;
	int cnt = 0;
	stack<int> st;
	st.push(0);
	for(int i = 0; i <= N; i++){
		while(!st.empty() && st.top()>y[i]){
			st.pop();
			cnt++;
		}
		if(st.top()!=y[i])
			st.push(y[i]);
	}
	printf("%d\n", cnt);
	return 0;
}
//你说得对，但是为什么我觉得这道题比T1简单，为啥放在T2
