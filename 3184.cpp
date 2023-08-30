#include <bits/stdc++.h>

using namespace std;

int len, l, r;

char s[60];

int main()
{

    cin >> s;

    len = strlen(s);

    l = (len - 1) / 2;

    r = l + 1;

    for (; r < len; --l, ++r)

        cout << s[l] << s[r];

    if (len % 2)

        cout << s[0];

    return 0;
}
