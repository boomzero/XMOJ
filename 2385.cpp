#include <bits/stdc++.h>

using namespace std;

char s[1010];

int n, i, len;

int numberRoot(int num)
{

    int x = 0;

    while (num)
    {

        x += num % 10;

        num /= 10;
    }

    return x;
}

int main()
{

    cin >> s;

    len = strlen(s);

    for (i = 0; i < len; ++i)

        n += (s[i] - '0');

    while (n >= 10)

        n = numberRoot(n);

    cout << n;

    return 0;
}
