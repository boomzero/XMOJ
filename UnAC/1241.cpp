#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    int e = unique(a.begin(), a.end()) - a.begin();
    cout << e << endl;
    for (int i = 0; i < e; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
