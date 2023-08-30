#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans *= i % 1000000007;
        ans %= 1000000007;
    }
    cout << ans % 1000000007 << endl;
    return 0;
}
