#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E6 + 10;
struct nod{
	bool v;
	int s1, s2;
	nod(bool _v, int _s1, int _s2): v(_v), s1(_s1), s2(_s2){}
};
string s;
int vh[MAXN];
void cal(nod &a, nod b, char op){
	if (op == '&')
		a = nod(a.v && b.v, a.s1 + b.s1, a.s2 + b.s2);
	else
		a = nod(a.v || b.v, a.s1 + b.s1, a.s2 + b.s2);
}
nod dfs(int l, int r){
	if (s[l] == '(' && vh[l] == r)
		return dfs(l + 1, r - 1);;
	nod ans = nod(false, 0, 0);
	nod ans1 = nod(true, 0, 0);
	nod tmp = nod(true, 0, 0);
	for(int i = l; i <= r; ++i){
		if(s[i] == '1' || s[i] == '0')
			tmp = nod(s[i] - '0', 0, 0);
		else if(s[i] == '(')
			tmp = dfs(i + 1, vh[i] - 1), i = vh[i];
		else if(s[i] == '|'){
			if(ans1.v)
				cal(ans1, tmp, '&');
			else
				ans1.s1++;
			if(!ans.v)
				cal(ans, ans1, '|');
			else
				ans.s2++;
			ans1=nod(true, 0, 0);
		}
		else if(ans1.v){
			cal(ans1, tmp, '&');
		}
		else
			ans1.s1++;
	}
	if(ans1.v)
		cal(ans1, tmp, '&');
	else
		ans1.s1++;
	if(!ans.v)
		cal(ans, ans1, '|');
	else
		ans.s2++;
	return ans;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin >> s;
	stack<int>stk;
	for (int i = 0; i < s.size(); ++i){
		if (s[i] == '(')
			stk.push(i);
		else if (s[i] == ')'){
			vh[stk.top()] = i;
			stk.pop();
		}
	}
	nod sol = dfs(0, s.size() - 1);
	cout<<sol.v<<endl;
	cout<<sol.s1<<" "<<sol.s2 << endl;
	return 0;
} 
