#include <bits/stdc++.h>
using namespace std;
int n, b, a[105] = {0}, cnt = 0;
int main()
{
    priority_queue<int, vector<int>, greater<>> pq;
    cin >> n >> b;
    if (n % 2)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 2; i < n; i += 2)
    { // i | i + 1
        int js = 0, os = 0;
        for (int j = 1; j <= i; ++j)
        {
            if (a[j] % 2)
                js++;
            else
                os++;
        }
        if (js != os)
        {
            continue;
        }
        js = 0, os = 0;
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[j] % 2)
                js++;
            else
                os++;
        }
        if (js != os)
        {
            continue;
        }
        int cost = abs(a[i] - a[i + 1]);
        pq.push(cost);
    }
    while (b > 0 && !pq.empty())
    {
        b -= pq.top();
        pq.pop();
        if (b < 0)
        {
            break;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
