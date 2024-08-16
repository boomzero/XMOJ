#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 200, LEN = (int)1e5;
const long long INF = (long long)1e15;
using namespace std;
inline void init(char *str, int len, int *pre)
{
	pre[0] = -1;
	for(int i = 1; i < len; ++ i){
		int p = pre[i - 1];
		for(; ~ p && str[p + 1] ^ str[i]; p = pre[p]);
		if(str[p + 1] == str[i])
			++ p;
		pre[i] = p;
	}
}
inline int mt(char *s, int len, char *t, int *pre){
	int p = -1;
	for(int i = 0; i < len; ++ i){
		for(; ~ p && t[p + 1] ^ s[i]; p = pre[p]); // 假如s和t是同一个串的话, 则要特判
		if(t[p + 1] == s[i] && (s != t || p + 1 < i))
			++ p;
	}
	return p + 1;
}
struct matrix{
	long long a[N][N];
	int n;
	inline matrix(int _n){
		n = _n;
	}
	inline matrix friend operator *(const matrix &A, const matrix &B){
		static matrix res(A.n);
		for(int i = 0; i < A.n; ++ i)
			for(int j = 0; j < A.n; ++ j){
				res.a[i][j] = INF;
				for(int k = 0; k < A.n; ++ k)
					res.a[i][j] = std::min(A.a[i][k] + B.a[k][j], res.a[i][j]);
			}
		return res;
	}
};
inline void power(matrix A, int x, matrix &res){
	for(; x; x >>= 1, A = A * A)
		if(x & 1)
			res = res * A;
}
inline int rd(){
	int ret=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=(ret<<1)+(ret<<3)+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
int main(){
	freopen("doll.in","r",stdin);
	freopen("doll.out","w",stdout);
	int n=rd(), m=rd();
	static char str[N][LEN];
	static int pre[N][LEN];
	for(int i = 0; i < n; ++ i)
		scanf("%s", str[i]),init(str[i], strlen(str[i]), pre[i]);
	static matrix A(n);
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < n; ++ j)
			A.a[i][j] = strlen(str[j]) - mt(str[i], strlen(str[i]), str[j], pre[j]);
	static matrix res(n);
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < n; ++ j)
			res.a[i][j]=i^j?INF:strlen(str[i]);
	power(A, m-1, res);
	long long ans = INF;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < n; ++ j)
			ans = min(ans, res.a[i][j]);
	printf("%lld", ans);
}
