#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[10001] = {0}, cnt = 1, ca[10001] = {0}, v = 0;
    cin >> n;
    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    while (cnt <= n)
    {
        if (!s.empty() && s.top() == a[cnt])
        {
            cnt++;
            s.pop();
        }
        else if (v <= n)
        {
            s.push(++v);
        }
        else
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    if (s.empty())
        cout << "Possible" << endl;
    else
        cout << "Impossible" << endl;
    return 0;
}
