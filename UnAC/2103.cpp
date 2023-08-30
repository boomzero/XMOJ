#include <iostream>
#include <limits>
typedef int mint;
#define int long long
using namespace std;
int getp(int n, const int *camp, int m, bool rSide)
{
    if (!rSide)
    {
        int ans = 0;
        for (int i = 1; i < m; ++i)
        {
            int i1 = camp[i] * (m - i);
            ans += i1;
        }
        return ans;
    }
    else
    {
        int ans = 0;
        for (int i = m + 1; i <= n; ++i)
        {
            ans += camp[i] * (i - m);
        }
        return ans;
    }
}
mint main()
{
    freopen("fight.in", "r", stdin);
    freopen("fight.out", "w", stdout);
    int n;
    cin >> n;
    int camp[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> camp[i];
    }
    int m, p1, s1, s2;
    cin >> m >> p1 >> s1 >> s2;
    camp[p1] += s1;
    int minPos = numeric_limits<int>::max(), minVal = numeric_limits<int>::max();
    int initL = getp(n, camp, m, false), initR = getp(n, camp, m, true);
    for (int i = 1; i <= n; ++i)
    {
        int lval = 0, rval = 0;
        if (i < m)
        {
            lval = initL + s2 * (m - i);
            rval = initR;
        }
        else if (i > m)
        {
            lval = initL;
            rval = initR + s2 * (i - m);
        }
        else
        {
            lval = initL;
            rval = initR;
        }
        if (abs(lval - rval) < minVal)
        {
            minVal = abs(lval - rval);
            minPos = i;
        }
    }
    cout << minPos << endl;
    return 0;
}
