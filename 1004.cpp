#include <bits/stdc++.h>

using namespace std;

int mat[20][20];

int main()
{

    int n, s, i, j;

    cin >> n >> s;

    for (i = 0; i < n; ++i)
    {

        for (j = 0; j <= i; ++j)
        {

            mat[j][i] = s++;

            if (s == 10)
                s = 1;
        }
    }

    for (i = 0; i < n; ++i)
    {

        if (mat[i][0])
            cout << mat[i][0];

        else
            cout << " ";

        for (j = 1; j < n; ++j)
        {

            cout << " ";

            if (mat[i][j])
                cout << mat[i][j];

            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}
