#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, value[N], parent[N];

bool p0(int x, int y)

{

    int tmp = parent[x];

    while (tmp)
    {

        if (tmp == y)
            return true;

        tmp = parent[tmp];
    }

    return false;
}

int p(int x, int y)

{

    if (p0(x, y))
        return y;

    if (p0(y, x))
        return x;

    return -1;
}

int main()

{

    cin >> n;

    for (int i = 1; i <= n; ++i)

        cin >> value[i] >> parent[i];

    int k, x, y;

    cin >> k;

    for (int i = 0; i < k; i++)
    {

        cin >> x >> y;

        cout << p(x, y) << endl;
    }

    return 0;
}
