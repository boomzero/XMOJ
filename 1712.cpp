#include <bits/stdc++.h>
using namespace std;
int n, m, t, x1, z1, x2, z2;
string f[100][100];
int cmp(string str1, string str2)
{
    if (str1.length() > str2.length())
        return 1;
    else if (str1.length() < str2.length())
        return -1;
    else
        return str1.compare(str2);
}
string add(string str1, string str2)
{
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 < len2)
        for (int i = 1; i <= len2 - len1; i++)
            str1 = "0" + str1;
    else
        for (int i = 1; i <= len1 - len2; i++)
            str2 = "0" + str2;
    len1 = str1.length();
    int cf = 0;
    int temp;
    for (int i = len1 - 1; i >= 0; i--)
    {
        temp = str1[i] - '0' + str2[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        str = char(temp + '0') + str;
    }
    if (cf != 0)
        str = char(cf + '0') + str;
    return str;
}
int main()
{
    cin >> n >> m >> t;
    if (t == 1)
        cin >> x1 >> z1 >> x2 >> z2;
    if (t == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1)
                    f[i][j] = '1';
                else if (j == 1)
                    f[i][j] = '1';
                else
                    f[i][j] = add(f[i - 1][j], f[i][j - 1]);
            }
        }
        cout << f[n][m];
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == 1)
                    f[i][j] = '1';
                else if (j == 1)
                    f[i][j] = '1';
                else if (i >= x1 && i <= x2 && j >= z1 && j <= z2)
                    f[i][j] = '0';
                else
                    f[i][j] = add(f[i - 1][j], f[i][j - 1]);
            }
        }
        cout << f[n][m];
    }
    return 0;
}
