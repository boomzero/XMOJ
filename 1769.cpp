#include <bits/stdc++.h>

using namespace std;

int r, c, n, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

char a[110][110], b[110][110], d[110];

bool win(int x1, int y1, int x2, int y2)

{

    char c1 = b[x1][y1], c2 = b[x2][y2];

    return (c1 == 'R' && c2 == 'S') || (c1 == 'S' && c2 == 'P') || (c1 == 'P' && c2 == 'R');
}

int main()

{

    cin >> r >> c >> n;

    memset(a, ' ', sizeof(a));

    for (int i = 1; i <= r; ++i)
    {

        cin >> d;

        for (int j = 1; j <= c; ++j)

            a[i][j] = d[j - 1];
    }

    for (int i = 1; i <= n; ++i)
    {

        memcpy(b, a, sizeof(a));

        for (int j = 1; j <= r; ++j)

            for (int k = 1; k <= c; ++k)

                for (int l = 0; l < 4; ++l)

                    if (win(j + dx[l], k + dy[l], j, k))

                        a[j][k] = b[j + dx[l]][k + dy[l]];
    }

    for (int i = 1; i <= r; ++i)
    {

        for (int j = 1; j <= c; ++j)
            cout << a[i][j];

        cout << endl;
    }

    return 0;
}
