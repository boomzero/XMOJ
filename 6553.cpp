#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> t;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        t.emplace_back(t1, t2);
    }
    sort(t.begin(), t.end(), [](auto a, auto b)
         { return a.second < b.second; });
    int now = 0;
    int ans = 0;
    priority_queue<pair<int, int>> q;
    for (auto i : t)
    {
        if (now + i.first <= i.second)
        {
            ans++;
            now += i.first;
            q.push(i);
        }
        else
        {
            if (i.first < q.top().first)
            {
                now -= (q.top().first - i.first);
                q.pop();
                q.push(i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
