#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{

    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{

    int n;

    scanf("%d", &n);

    int num[n];

    for (int i = 0; i < n; i++)
    {

        scanf("%d", &num[i]);
    }

    int ans = 0;

    sort(num, num + n);

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (gcd(num[i], num[j]) == 1 && num[i] < num[j])
            {

                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
