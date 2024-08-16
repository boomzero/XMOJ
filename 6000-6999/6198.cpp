#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 100
class hash {
	private:
		unsigned long long h[MAXN + 5], b[MAXN + 5];
	public:
		int initial (char *c){
			int n = strlen (c);
			
			b[0] = 1;
			h[0] = 0;
			for (int i = 1; i <= n; i++){
				h[i] = h[i - 1] * 1331 + c[i - 1];
				b[i] = b[i - 1] * 1331;
			}
			return n;
		}
		unsigned long long access (int l, int r){
			return h[r + 1] - h[l] * b[r - l + 1];
		}
};
hash s;
int dp[3][MAXN + 5][MAXN + 5];
char c[MAXN + 5];
int main(){
	int n;
	scanf ("%s", c + 1);
	n = s.initial(c + 1);
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n - i + 1; j++){
			dp[1][j][j + i - 1] = i;
			dp[0][j][j + i - 1] = 0x7f7f7f7f;
			dp[2][j][j + i - 1] = i;
			if (i % 2 == 0) {
				if (s.access(j - 1, j + i / 2 - 2) == s.access(j + i / 2 - 1, j + i - 2)){
					dp[0][j][j + i - 1] = min (dp[1][j][j + i / 2 - 1] + 2, dp[0][j][j + i / 2 - 1] + 1);
				}
			}
			if (j == 1){
				dp[0][j][j + i - 1] = min (i, dp[0][j][j + i - 1]);
			}
			for (int k = j; k < i + j - 1; k++){
				dp[1][j][j + i - 1] = min (dp[1][j][j + i - 1], dp[1][j][k] + dp[1][k + 1][j + i - 1]);//合并
				dp[0][j][j + i - 1] = min (dp[0][j][j + i - 1], dp[0][j][k] + dp[1][k + 1][j + i - 1]);
				dp[2][j][j + i - 1] = min (dp[2][j][j + i - 1], min (dp[0][j][k], min (dp[1][j][k], dp[2][j][k])) + min (dp[0][k + 1][i + j - 1], min (dp[1][k + 1][i + j - 1], dp[2][k + 1][i + j - 1])));
			}
		}
	}
	printf("%d", min (dp[0][1][n], min (dp[1][1][n], dp[2][1][n])));
}
