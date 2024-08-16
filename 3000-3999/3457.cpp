#include <bits/stdc++.h>
using namespace std;
inline int block(int x) {
	return x / 220;
}
struct Query {
	int l, r, id;
	bool operator<(const Query &rhs) const {
		return make_pair(block(l), r)<make_pair(block(rhs.l),rhs.r);
	}
};
template <void (*add)(int &, int), void (*del)(int &, int)> struct Mo_Algo {
	int n, q, a[50005], L, R;
	vector<Query> queries;
	void add_query(int l, int r) {
		queries.push_back({l, r, q++});
	}
	int &operator[](int x) {
		return a[x];
	}
	vector<int> get_ans() {
		sort(queries.begin(), queries.end());
		vector<int> ans = vector<int>(queries.size());
		L = 1;
		R = 0;
		int ans_t = 0;
		for (auto [l, r, id] : queries) {
			ans[id]=ans_t;
			while (L < l)
				del(ans[id], a[L]), L++;
			while (L > l)
				L--, add(ans[id], a[L]);
			while (R < r)
				R++, add(ans[id], a[R]);
			while (R > r)
				del(ans[id], a[R]), R--;
			ans_t = ans[id];
		}
		return ans;
	}
};
int buc[50005];
void add(int &a, int b) {
	buc[b]++;
	if (buc[b] == 3)
		a++;
}
void del(int &a, int b) {
	if (buc[b] == 3)
		a--;
	buc[b]--;
}
Mo_Algo<add, del> mo;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	cin >> mo[i];
	while (m--) {
		int l, r;
		cin >> l >> r;
		mo.add_query(l, r);
	}
	for (auto x : mo.get_ans())
		cout << x << endl;
	return 0;
}
