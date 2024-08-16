#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
long long N;
long long d[MAXN];
int main() {
	freopen("infect.in", "r", stdin);
	freopen("infect.out", "w", stdout);
    cin >> N;
    long long a, b;
	for (long long i = 0; i < N - 1; i++) {
    	cin >> a >> b;
        a--, b--;
        d[a]++, d[b]++;
    }
    long long ans = N - 1;
    for (long long i = 0; i < N; i++)
        if (d[i] > 1 || i == 0) {
           long long children = d[i];
           if (i != 0) children--;
           long long log_children = 0;
           long long pow = 1;
           while (pow < children + 1)
               log_children++, pow *= 2;
           ans += log_children;
    }
    cout << ans;
    return 0;
}
