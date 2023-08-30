#include <bits/stdc++.h>
#include <chrono>
#define int long long
using namespace std;
int n, ans = numeric_limits<int>::max();
vector<pair<int, int>> d;
int a[100005], b[100005];
int f(int i)
{
    i--;
    int y = d[i].second, cans = 0;
    for (int j = 0; j < n; j++)
    {
        cans += min(abs(d[j].first - d[j].second), abs(d[j].first) + abs(y - d[j].second));
    }
    ans = min(cans, ans);
    return cans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("move.in", "r", stdin);
    freopen("move.out", "w", stdout);
    cin >> n;
    if (n <= 1000)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
        }
        for (int i = 1; i <= n; i++)
        {
            int y = b[i], cans = 0;
            for (int j = 1; j <= n; j++)
            {
                cans += min(abs(a[j] - b[j]), abs(a[j]) + abs(y - b[j]));
            }
            // cout << cans << endl;
            ans = min(ans, cans);
        }
        cout << ans << endl;
        return 0;
    }
    auto start = chrono::high_resolution_clock::now();
    if (n == 0)
        return 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        d.emplace_back(a, b);
    }
    sort(d.begin(), d.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    int l = 1, r = n;
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        int mmid = (mid + r) / 2;
        if (f(mid) > f(mmid))
            l = mid;
        else
            r = mmid;
    }
    f(1);
    f(n);
    srand(time(0));
    auto end = chrono::high_resolution_clock::now();
    while (chrono::duration_cast<chrono::milliseconds>(end - start).count() < 50)
    {
        end = chrono::high_resolution_clock::now();
        l = rand() % n;
        r = rand() % n;
        while (l < r - 1)
        {
            int mid = (l + r) / 2;
            int mmid = (mid + r) / 2;
            if (f(mid) > f(mmid))
                l = mid;
            else
                r = mmid;
        }
    }
    cout << ans << endl;
    return 0;
}
