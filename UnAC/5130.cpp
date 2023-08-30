#include <bits/stdc++.h>
using namespace std;
int val(int num)
{
    switch (num)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 5;
    case 5:
        return 10;
    case 6:
        return 20;
    default:
        return 0;
    }
}
int main()
{
    int a[7] = {0}, n = 0, w[2000] = {0}, p = 0, dp[3000] = {0};
    for (int i = 1; i <= 6; ++i)
    {
        cin >> a[i];
        n += a[i];
        for (int j = 0; j < a[i]; ++j)
        {
            p++;
            w[p] = val(i);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1000; j >= w[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
        }
    }
    set<int> el;
    int ans = 0;
    for (int i : dp)
    {
        if (i != 0 && !el.count(i))
        {
            el.insert(i);
            ans++;
        }
    }
    cout << "Total=" << ans << endl;
    return 0;
}
