#include <bits/stdc++.h>

using namespace std;

const int MALE = 1, FEMALE = 2;

int n, g[50];

double height[50];

char s[10];

int main()
{

    cin >> n;

    for (int i = 0; i < n; ++i)
    {

        cin >> s >> height[i];

        if (s[0] == 'm')

            g[i] = MALE;

        else

            g[i] = FEMALE;
    }

    for (int i = n - 1; i > 0; --i)
    {

        for (int j = 0; j < i; ++j)
        {

            bool f;

            if (g[j] != g[j + 1])
            {

                f = g[j] > g[j + 1];
            }
            else if (g[j] == MALE)
            {

                f = height[j] > height[j + 1];
            }
            else
            {

                f = height[j] < height[j + 1];
            }

            if (f)
            {

                swap(g[j], g[j + 1]);

                swap(height[j], height[j + 1]);
            }
        }
    }

    cout << setprecision(2) << fixed << height[0];

    for (int i = 1; i < n; ++i)

        cout << " " << height[i];

    return 0;
}
