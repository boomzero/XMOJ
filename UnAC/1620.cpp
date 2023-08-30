#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p;
    for (int i = 1; i <= n; ++i)
    {
        p.push_back(i);
    }
    for (int i = 1; i < k; ++i)
    {
        next_permutation(p.begin(), p.end());
    }
    bool f = true;
    for (int i : p)
    {
        if (!f)
            putchar(' ');
        f = false;
        cout << i;
    }
    cout << endl;
    return 0;
}
