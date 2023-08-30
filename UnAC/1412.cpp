#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[200] = {0};
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    int tg = sum / n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != tg)
        {
            ans++;
            a[i + 1] += (a[i] - tg);
        }
    }
    cout << ans << endl;
    return 0;
}
