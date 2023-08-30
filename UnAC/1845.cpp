#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), [](int a, int b)
         { return a > b; });
    for (int i : a)
    {
        cout << i << endl;
    }
    return 0;
}
