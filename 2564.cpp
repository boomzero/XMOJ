#include <bits/stdc++.h>
using namespace std;
long long a, b, ans = 1, i;
int main()
{
    cin >> a >> b;
    for (i = a + 1; i <= b; ++i)
    {
        ans *= i % 10;
        ans %= 10;
        if (ans == 0)
            break;
    }
    cout << ans;
    return 0;
}
