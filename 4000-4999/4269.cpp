#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
long long N, inc_exc[] = {-1, +1, -1, +1, -1, +1};
struct S5
{
	int n;
	int v[5];
};
S5 A[100000];
bool operator<(const S5 &a, const S5 &b)
{
	for (int j = 0; j < 5; j++)
	{
		if (a.v[j] < b.v[j])
			return true;
		if (a.v[j] > b.v[j])
			return false;
	}
	return false;
}
S5 get_subset(S5 &a, int x)
{
	S5 result = {0, {0, 0, 0, 0, 0}};
	for (int j = 0; j < 5; j++)
		if ((1 << j) & x)
			result.v[result.n++] = a.v[j];
	return result;
}
map<S5, int> subsets;
int main(void)
{
	freopen("hobby.in", "r", stdin);
	scanf("%lld", &N);
	for (int i = 0; i < N; i++)
	{
		A[i].n = 5;
		for (int j = 0; j < 5; j++)
			scanf("%d", &A[i].v[j]);
		sort(A[i].v, A[i].v + 5);
		for (int x = 1; x < 32; x++)
			subsets[get_subset(A[i], x)]++;
	}
	long long answer = N * (N - 1) / 2;
	for (auto &p : subsets)
		answer -= inc_exc[p.first.n] * p.second * (p.second - 1) / 2;
	freopen("hobby.out", "w", stdout);
	printf("%lld", answer);
	return 0;
}
