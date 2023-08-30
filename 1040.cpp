#include <bits/stdc++.h>

using namespace std;

int n, i, j, k, tmp, ans;

// int a[30000][30000] 内存超限

int main()

{

    freopen("matrix.in", "r", stdin);

    freopen("matrix.out", "w", stdout);

    cin >> n >> i >> j;

    tmp = min(i - 1, n - i);

    tmp = min(tmp, j - 1);

    tmp = min(tmp, n - j);

    ans = 4 * n * tmp - 4 * tmp * tmp;

    if (i - tmp == 1)
    {

        ans += j - tmp;
    }

    else

        if (i + tmp == n)
    {

        ans += 3 * n - 5 * tmp - 1 - j;
    }

    else

        if (j - tmp == 1)
    {

        ans += 4 * n - 7 * tmp - 2 - i;
    }

    else
    {

        ans += n - 3 * tmp + i - 1;
    }

    cout << ans;

    fclose(stdin);

    fclose(stdout);

    return 0;
}
