#include <bits/stdc++.h>
int bucket[601] = {0};
using namespace std;
int score[100001];
int line(int w, int p)
{
    bucket[score[p]]++;
    int pass = max(1, p * w / 100);
    int people = 0;
    for (int i = 600; i >= 0; --i)
    {
        people += bucket[i];
        if (people >= pass)
        {
            return i;
        }
    }
}
int main()
{
    freopen("live.in", "r", stdin);
    freopen("live.out", "w", stdout);
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
    {
        cin >> score[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << line(w, i) << " ";
    }
    cout << endl;
    return 0;
}
