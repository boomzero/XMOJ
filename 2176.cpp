#include <bits/stdc++.h>

using namespace std;

int n, m, a[100010];

// 第一个小于x的数

int a1(int x)
{

    int l = 1, r = n, mid;

    while (l <= r)
    {

        mid = (l + r) / 2;

        if (a[mid] >= x)
            l = mid + 1;

        else
            r = mid - 1;
    }

    if (l <= n)
        return l;

    return -1;
}

// 第一个小于等于x的数

int a2(int x)
{

    int l = 1, r = n, mid;

    while (l <= r)
    {

        mid = (l + r) / 2;

        if (a[mid] > x)
            l = mid + 1;

        else
            r = mid - 1;
    }

    if (l <= n)
        return l;

    return -1;
}

// 最后一个大于x的数

int a3(int x)
{

    int l = 1, r = n, mid;

    while (l <= r)
    {

        mid = (l + r) / 2;

        if (a[mid] > x)
            l = mid + 1;

        else
            r = mid - 1;
    }

    if (r >= 1)
        return r;

    return -1;
}

// 最后一个大于等于x的数

int a4(int x)
{

    int l = 1, r = n, mid;

    while (l <= r)
    {

        mid = (l + r) / 2;

        if (a[mid] >= x)
            l = mid + 1;

        else
            r = mid - 1;
    }

    if (r >= 1)
        return r;

    return -1;
}

// 第一个大于x的数

int a5(int x)
{

    if (x < a[1])
        return 1;

    else
        return -1;
}

// 最后一个小于x的数

int a6(int x)
{

    if (a[n] < x)
        return n;

    else
        return -1;
}

int main()
{

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)

        scanf("%d", &a[i]);

    for (int i = 1, x; i <= m; ++i)
    {

        scanf("%d", &x);

        printf("%d %d %d %d %d %d\n",

               a1(x), a2(x), a3(x), a4(x), a5(x), a6(x));
    }

    return 0;
}
