#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int k, x;

int n, v[N], left_child[N], right_sibling[N], root, ans;

int sum(int x)

{

    for (int i = left_child[x]; i; i = right_sibling[i])

        ans += v[i];

    return ans;
}

int main()

{

    ios::sync_with_stdio(false);

    scanf("%d%d", &n, &root);

    for (int i = 1; i <= n; ++i)
    {

        scanf("%d%d%d", &v[i], &left_child[i], &right_sibling[i]);
    }

    scanf("%d", &k);

    while (k--)
    {

        ans = 0;

        scanf("%d", &x);

        printf("%d\n", sum(x));
    }

    return 0;
}
