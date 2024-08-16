#include <bits/stdc++.h>
typedef long long LL;
const int N = 2e6 + 5;
int n;
char s[N];
int cnt[N], nxt[N][26];
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; i++) s[i] -= 'a';
	for(int i = n - 1; i >= 1; i--) {
		if(s[i + 1] == s[i]) {
			for(int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 2][j];
			if(i + 2 <= n) nxt[i][s[i + 2]] = i + 2;
			cnt[i] = cnt[i + 2] + 1;
//			printf("%d -> %d\n", i, i + 2);
		}
		else if(nxt[i + 1][s[i]]) {
			int i_ = nxt[i + 1][s[i]];
			for(int j = 0; j < 26; j++)
				nxt[i][j] = nxt[i_ + 1][j];
			if(i_ + 1 <= n) nxt[i][s[i_ + 1]] = i_ + 1;
			cnt[i] = cnt[i_ + 1] + 1;
//			printf("%d -> %d\n", i, i_ + 1);
		}
	}
	LL ans = 0;
	for(int i = 1; i <= n; i++)
		ans += cnt[i];
	printf("%lld\n", ans);
	return 0;
}
