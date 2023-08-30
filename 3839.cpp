#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, A[N], L[N], R[N];

int Sta[N], Top;

int main()
{

	freopen("d.in", "r", stdin);

	freopen("d.out", "w", stdout);

	ios::sync_with_stdio(false);

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)

		scanf("%d", &A[i]);

	for (int i = 1; i <= n; ++i)
	{

		if ((!Top) || (A[Sta[Top]] < A[i]))

			L[i] = Sta[Top];

		else
		{

			while (Top && A[Sta[Top]] > A[i])

				R[Sta[Top--]] = i;

			L[i] = Sta[Top];
		}

		Sta[++Top] = i;
	}

	while (Top)

		R[Sta[Top--]] = n + 1;

	long long Ans = 0;

	for (int i = 1; i <= n; ++i)

		Ans += 1ll * A[i] * (i - L[i]) * (R[i] - i);

	printf("%lld\n", Ans);

	return 0;
}
