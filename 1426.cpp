#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

const int MAXM = 501;

struct seg
{
    int x, y, t;
} a[MAXM];

int n, m, used[MAXN], ans;

bool cmp(const seg &a, const seg &b)

{

    if (a.y != b.y)
        return a.y < b.y;

    return a.x < b.x;
}

int main()

{

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
        cin >> a[i].x >> a[i].y >> a[i].t;

    sort(a, a + m, cmp);

    for (int i = 0; i < m; ++i)
    {

        int k = 0;

        for (int j = a[i].x; j <= a[i].y; ++j)
            k += used[j];

        if (k < a[i].t)

            for (int j = a[i].y; j >= a[i].x; --j)

                if (!used[j])
                {

                    used[j] = 1;

                    ++ans;

                    if (++k == a[i].t)
                        break;
                }
    }

    cout << ans << endl;

    return 0;
}
