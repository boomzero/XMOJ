#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int n, num[100001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }
    if (n == 1)
    {
        cout << num[0] << endl;
        return 0;
    }
    int ans = gcd(num[0], num[1]);
    for (int i = 3; i < n; ++i)
    {
        ans = gcd(ans, num[i]);
    }
    cout << abs(ans) << endl;
    return 0;
}
