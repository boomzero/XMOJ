#include <bits/stdc++.h>

using namespace std;

int s, a, b, d, n = 0;

int a1, a2, a3, b1, b2, b3;

bool judge(int x)

{

    int c1 = (a1 - a + x) * b1;

    int c2 = (a2 - a + x) * b2;

    int c3 = (a3 - a + x) * b3;

    if (c2 >= c1 && c2 >= c3)

        return 1;

    else

        return 0;
}

int main()

{

    cin >> s;

    cin >> a >> b;

    int i;

    a1 = s - 1;

    a2 = s;

    a3 = s + 1;

    int p1 = a, p2 = b;

    for (i = 0;; i++)

    {

        int temp1, temp2;

        cin >> temp1 >> temp2;

        if (temp1 == -1 && temp2 == -1)

            break;

        if (temp1 == a1)

            b1 = temp2;

        else if (temp1 > a1 && a1 > p1)

            b1 = p2 + (temp2 - p2) / (temp1 - p1) * (a1 - p1);

        if (temp1 == a2)

            b2 = temp2;

        else if (temp1 > a2 && a2 > p1)

            b2 = p2 + (temp2 - p2) / (temp1 - p1) * (a2 - p1);

        if (temp1 == a3)

            b3 = temp2;

        else if (temp1 > a3 && a3 > p1)

            b3 = p2 + (temp2 - p2) / (temp1 - p1) * (a3 - p1);

        n++;

        p1 = temp1;

        p2 = temp2;
    }

    cin >> d;

    if (a1 > p1)
        b1 = p2 - (a1 - p1) * d;

    if (a2 > p1)
        b2 = p2 - (a2 - p1) * d;

    if (a3 > p1)
        b3 = p2 - (a3 - p1) * d;

    for (int i = 0; i < 1e9; i++)

    {

        if (judge(i))

        {

            cout << i;

            return 0;
        }

        if (judge(-i))

        {

            cout << -i;

            return 0;
        }
    }

    cout << "NO SOLUTION";

    return 0;
}
