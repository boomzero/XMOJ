#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[100], op, c1, c2;
    int len = 0, n;
    while ((str[len] = getchar()) != '.')
        ++len;
    str[++len] = '\0';
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> op;
        if (op == 'D')
        {
            cin >> c1;
            for (int j = 0; j < len; ++j)
                if (str[j] == c1)
                {
                    for (int k = j + 1; k <= len; ++k)
                        str[k - 1] = str[k];
                    --len;
                    break;
                }
            cout << str << endl;
        }
        else if (op == 'I')
        {
            cin >> c1 >> c2;
            for (int j = len - 1; j >= 0; --j)
                if (str[j] == c1)
                {
                    for (int k = len; k >= j; --k)
                        str[k + 1] = str[k];
                    str[j] = c2;
                    ++len;
                    break;
                }
            cout << str << endl;
        }
        else if (op == 'R')
        {
            cin >> c1 >> c2;
            bool found = false;
            for (int j = 0; j < len; ++j)
            {
                if (str[j] == c1)
                {
                    str[j] = c2;
                    found = true;
                }
            }
            if (found)
                cout << str << endl;
            else
                cout << "Not found" << endl;
        }
    }
    return 0;
}
