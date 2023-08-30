#include <bits/stdc++.h>

using namespace std;

struct BigDecimal
{

    int val[50];

    BigDecimal()
    {

        memset(val, 0, sizeof(val));

        val[0] = 1;
    }

    BigDecimal(char str[], int start, int end)
    {

        reset(str, start, end);
    }

    void reset(char str[], int start, int end)
    {

        while (start < end && val[start] == '0')
            ++start; // 去掉前导0。是否应该有前导0，题面上有歧义。

        val[0] = end - start + 1;

        for (int i = val[0], j = start; i >= 1; --i, ++j)

            val[i] = str[j] - '0';
    }

    BigDecimal operator*(const BigDecimal &x) const
    {

        BigDecimal y;

        for (int i = 1; i <= val[0]; ++i)

            for (int j = 1; j <= x.val[0]; ++j)

                y.val[i + j - 1] += val[i] * x.val[j];

        int ii, carry = 0;

        for (ii = 1; ii <= val[0] + x.val[0] - 1 || carry > 0; ++ii)
        {

            y.val[ii] += carry;

            carry = y.val[ii] / 10;

            y.val[ii] %= 10;
        }

        y.val[0] = ii - 1;

        return y;
    }

    bool operator<(const BigDecimal &x) const
    {

        if (val[0] != x.val[0])
            return val[0] < x.val[0];

        for (int i = val[0]; i >= 1; --i)

            if (val[i] != x.val[i])

                return val[i] < x.val[i];

        return true;
    }

    void print()
    {

        for (int i = val[0]; i >= 1; --i)

            cout << val[i];
    }

} f[41][7];

int main()

{

    int n, m;

    char s[50];

    cin >> n >> m >> s;

    for (int i = 1; i <= n; ++i)
        f[i][0].reset(s, 0, i - 1);

    for (int i = 2; i <= n; ++i)

        for (int j = 1; j <= min(i - 1, m); ++j)

            for (int k = j; k <= i - 1; ++k)
            {

                BigDecimal tmp1(s, k, i - 1);

                BigDecimal tmp2 = f[k][j - 1] * tmp1;

                if (f[i][j] < tmp2)
                    f[i][j] = tmp2;
            }

    f[n][m].print();

    cout << endl;
}
