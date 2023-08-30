#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        if (!m.count(p))
            m[p] = 0;
        m[p]++;
    }
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}
