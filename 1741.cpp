#include <bits/stdc++.h>

using namespace std;

int n, ns = 1;

char tree[3000];

string s, p = "BIF"; // string to make sure how the string is

void make(int jd)

{

    if (jd >= ns)
    {

        tree[jd] = p[s[jd - ns] - '0'];
        return;
    }

    make(jd * 2);

    make(jd * 2 + 1);

    if (tree[jd * 2] == 'B' && tree[jd * 2 + 1] == 'B')

        tree[jd] = 'B';

    else if (tree[jd * 2] == 'I' && tree[jd * 2 + 1] == 'I')

        tree[jd] = 'I';

    else

        tree[jd] = 'F';
}

void print(int jd)

{

    if (jd < ns)
    {

        print(jd * 2);

        print(jd * 2 + 1);
    }

    cout << tree[jd];
}

int main()

{

    cin >> n >> s;

    for (int i = 1; i <= n; ++i)

        ns *= 2; // calculate maximum extent

    make(1);

    print(1);

    return 0;
}
