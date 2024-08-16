#include <bits/stdc++.h>

using namespace std;
struct recsss {
    int p = 0, s = 0;
};
bool sortCmp(recsss a, recsss b){
    if (a.p+a.s>b.p+b.s) return false;
    return true;
}
int main() {
    freopen("gifts.in","r",stdin);
    freopen("gifts.out","w",stdout);
    int n, b;
    cin >> n >> b;
    recsss ress[1001];
    for (int i = 0; i < n; ++i) {
        cin >> ress[i].p >> ress[i].s;
    }
    sort(ress, ress + n, sortCmp);
    int moneyUsed=0,wish=0,i=0;
    while(moneyUsed<b){
        moneyUsed+=ress[i].p;
        moneyUsed+=ress[i].s;
        i++;
    }
    i--;
    if (moneyUsed - ress[i].p / 2 <= b) cout << i + 1 << endl;
    else cout<<i<<endl;
    return 0;
}

