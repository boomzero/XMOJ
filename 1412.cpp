#include <bits/stdc++.h>
using namespace std;
int n, avg, p[101], ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        avg += p[i];
    }
    avg /= n;
    for (int i = 0; i < n; ++i)
        p[i] -= avg;
    for (int i = 0; i < n; ++i)
    {
        if (p[i] != 0)
        {
            p[i + 1] += p[i];
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
