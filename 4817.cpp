#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 60;

ll K, k;

ll a[maxn];

int main()

{

    freopen("seq.in", "r", stdin);

    freopen("seq.out", "w", stdout);

    scanf("%lld", &K);
    k = K % 50ll;

    for (int i = 50; i > 50 - k; i--)
        a[i] = 50;

    for (int i = 50 - k; i >= 1; i--)
        a[i] = 50 - k - 1;

    k = K / 50ll;

    for (int i = 1; i <= 50; i++)
        a[i] += k;

    printf("50\n");

    for (int i = 1; i <= 50; i++)
        printf("%lld ", a[i]);

    return 0;
}
