#include <bits/stdc++.h>

using namespace std;

int len, cnt[26];

char w[200];

int main()

{

    cin >> w;

    len = strlen(w);

    for (int i = 0; i < len; ++i)

        ++cnt[w[i] - 'a'];

    for (int i = 0; i < 26; ++i)

        if (cnt[i] % 2)
        {

            cout << "No" << endl;

            return 0;
        }

    cout << "Yes" << endl;

    return 0;
}
