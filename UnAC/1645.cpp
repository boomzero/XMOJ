#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int classes[10] = {0}, n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> classes[i];
    }
    int ans = classes[1];
    for (int i = 2; i <= n; ++i)
    {
        ans = lcm(ans, classes[i]);
    }
    cout << ans << endl;
    return 0;
}
