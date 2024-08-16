#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
const int R = 50000;
struct Node {
    int x, y, d;
};
int n, r;
Node node[R+1];
int pre[N+1];
int rnk[N+1];
bool cmp(const Node& a, const Node& b){
    return a.d < b.d;
}
void init(){
    for (int i = 1; i <= n; i ++) {
        pre[i] = i;
		rnk[i] = 0;
    }
}
int find(int a){
    while (a != pre[a])
        a = pre[a];
    return a;
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (rnk[a] < rnk[b]) {
        pre[a] = b;
    }
    else {
        pre[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a] ++;
    }
}
bool same(int a, int b){
    return find(a) == find(b);
}
int kruskal(){
    sort(node+1, node+r+1, cmp);
    int res = 0;
    for (int i = 1; i <= r; i ++) {
        int x = node[i].x, y = node[i].y;
        if (!same(x, y)) {
            unite(x, y);
            res += node[i].d;
        }
    }
    return res;
}
int main(void){
	freopen("recruit.in", "r", stdin);
	freopen("recruit.out", "w", stdout);
    int n1, n2;
    cin >> n1 >> n2 >> r;
    n = n1 + n2;
    int x, y, d;
    for (int i = 1; i <= r; i ++) {
        scanf("%d%d%d", &x, &y, &d);
        node[i].x = x + 1;
        node[i].y = n1 + y + 1;
        node[i].d = -d;
    }
    init();
    printf("%d\n", 10000 * n + kruskal());
    return 0;
}   
