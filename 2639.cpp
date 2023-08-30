#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        ans = 0;
        while (a > 0 && b > 0)
        {
            if (a < b)
                swap(a, b);
            ans = ans + a / b;
            a = a % b;
        }
        cout << ans << endl;
    }
    return 0;
}
