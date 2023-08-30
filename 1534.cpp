#include <bits/stdc++.h>

using namespace std;

int n, a[1010];

stack<int> sta;

int main()

{

    cin >> n;

    for (int i = 1; i <= n; ++i)

        cin >> a[i];

    for (int i = 1, current = 1; i <= n; ++i)
    {

        while (current <= a[i])
        {

            sta.push(current++);
        }

        if (sta.top() == a[i])
        {

            int x = sta.top();

            sta.pop();
        }

        else
        {

            cout << "Impossible";

            return -1;
        }
    }

    cout << "Possible";

    return -1;
}
