#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, value[N], father[N];
int s(int x)
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (father[i] == x)
            ans += value[i];
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> value[i] >> father[i];
    int k, x;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> x;
        cout << s(x) << endl;
    }
    return 0;
}
