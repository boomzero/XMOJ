#include <bits/stdc++.h>

using namespace std;

int p, q, r, f;

char ch, op;

int main()

{

    freopen("expr.in", "r", stdin);

    freopen("expr.out", "w", stdout);

    while (true)

    {

        ch = getchar();

        if (!('0' <= ch && ch <= '9' || ch == '+' || ch == '*'))

            break;

        q = 0;

        while ('0' <= ch && ch <= '9')

        {

            q = (q * 10 + ch - '0') % 10000;

            ch = getchar();
        }

        while (ch == '*')

        {

            r = 0;

            ch = getchar();

            while ('0' <= ch && ch <= '9')

            {

                r = (r * 10 + ch - '0') % 10000;

                ch = getchar();
            }

            q = (q * r % 10000) % 10000;
        }

        p = (p + q) % 10000;
    }

    cout << p;

    return 0;
}
