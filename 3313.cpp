#include <bits/stdc++.h>

using namespace std;

long long n;

long long x = 0;

priority_queue<long long, vector<long long>, greater<long long>> que;

int main()

{

    cin >> n;

    que.push(1);

    for (long long i = 1; i <= n; ++i)
    {

        while (x == que.top())
        {

            que.pop();
        }

        x = que.top();

        que.pop();

        que.push(x * 2);

        que.push(x * 3);

        que.push(x * 5);

        que.push(x * 7);
    }

    cout << x;

    return 0;
}
