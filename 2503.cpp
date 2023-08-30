#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, a, b, c, d;

    cin >> n;

    d = n % 10;

    n /= 10;

    c = n % 10;

    n /= 10;

    b = n % 10;

    a = n / 10;

    if (a)

        cout << 4;

    else if (b)

        cout << 3;

    else if (c)

        cout << 2;

    else

        cout << 1;

    cout << " " << a + b + c + d;

    return 0;
}
