#include <bits/stdc++.h>

using namespace std;

int n, s;

pair<int, int> ball[200010];

int main()

{

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {

        scanf("%d%d", &ball[i].second, &ball[i].first);
    }

    sort(ball + 1, ball + n + 1);

    int m = 0, i = 1, j = n;

    while (i <= j)
    {

        int x = min(ball[i].second, ball[j].second);

        if (i == j)

            x /= 2;

        m = max(m, ball[i].first + ball[j].first);

        ball[i].second -= x;

        ball[j].second -= x;

        if (ball[i].second == 0)

            i++;

        if (ball[j].second == 0)

            j--;
    }

    printf("%d", m);

    return 0;
}
