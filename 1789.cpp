#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 2200000;
const int mod = 2181271;
int hash[maxn];
struct z
{
	int next, v;
} z[maxn];
bool count(int tmp, int tmpp)
{
	for (int i = hash[tmpp]; i; i = z[i].next)
		if (tmp == z[i].v)
			return 1;
	return 0;
}
int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	hash[1] = z[1].v = 1;
	int tmp = 1;
	for (int i = 1; i <= 2000000; i++)
	{
		tmp = ((ll)a * tmp + tmp % b) % c;
		int tmpp = tmp % mod;
		if (count(tmp, tmpp))
		{
			printf("%d\n", i);
			return 0;
		}
		z[i + 1].v = tmp;
		z[i + 1].next = hash[tmpp];
		hash[tmpp] = i + 1;
	}
	puts("-1");
	return 0;
}
