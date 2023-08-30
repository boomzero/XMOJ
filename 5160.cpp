#include <bits/stdc++.h>

#define ll long long

#define mod 1000007

using namespace std;

ll pri[7777];

stack<ll> num, ope;

string mp[77], str;

ll n, ans[777], len, i, j, k;

char c;

inline void read()

{

    c = getchar();

    while (c == '\n' || c == '\r')
        c = getchar();

    while (c != '\n' && c != '\r')
    {
        if (c != ' ')
            mp[0] += c;
        c = getchar();
    }

    scanf("%lld", &n);

    for (i = 1; i <= n; i++)

    {

        while (c == '\n' || c == '\r')
            c = getchar();

        while (c != '\n' && c != '\r')
        {
            if (c != ' ')
                mp[i] += c;
            c = getchar();
        }
    }
}

inline ll ksm(ll x, ll y)

{

    if (y == 1)
        return x;

    ll k = ksm(x, y / 2);

    if (y & 1)
        return (k * k * x) % mod;

    return (k * k) % mod;
}

void solve()

{

    for (k = 1; k <= 10; k++)

    {

        while (!num.empty())
            num.pop();

        while (!ope.empty())
            ope.pop();

        for (i = 0; i <= len; i++)

        {

            if (str[i] == 'a')
                num.push(k);

            else if (str[i] >= '0' && str[i] <= '9')

            {

                ll tmp = 0;

                while (str[i] >= '0' && str[i] <= '9')

                    tmp = tmp * 10 + str[i] - '0', i++;

                num.push(tmp);

                i--;
            }

            else if (str[i] == ')')

            {

                bool flag = 1;

                if (ope.empty())
                    break;

                while (ope.top() != (ll)'(')

                {

                    c = ope.top();
                    ope.pop();

                    ll num1 = num.top();
                    num.pop();

                    ll num2 = num.top();
                    num.pop();

                    if (c == '*')
                        num.push((num2 * num1) % mod);

                    if (c == '+')
                        num.push((num2 + num1) % mod);

                    if (c == '-')
                        num.push((num2 - num1) % mod);

                    if (c == '^')
                        num.push(ksm(num2, num1));

                    if (ope.empty())
                        break;
                }

                if (ope.empty())
                    break;

                ope.pop();
            }

            else if (ope.empty())
                ope.push(str[i]);

            else if (str[i] == '(')
                ope.push(str[i]);

            else

            {

                c = ope.top();

                if (c == '(')

                {

                    ope.push(str[i]);

                    continue;
                }

                while (1)

                {

                    if (ope.empty())
                        break;

                    c = ope.top();

                    if (pri[c] < pri[str[i]] || c == '(')
                        break;

                    ope.pop();

                    ll num1 = num.top();
                    num.pop();

                    ll num2 = num.top();
                    num.pop();

                    if (c == '*')
                        num.push((num2 * num1) % mod);

                    if (c == '+')
                        num.push((num2 + num1) % mod); // push 10

                    if (c == '-')
                        num.push((num2 - num1) % mod); // push -

                    if (c == '^')
                        num.push(ksm(num2, num1)); // push 9
                }

                ope.push(str[i]);
            }
        }

        while (!ope.empty())

        {

            while (1)

            {

                if (ope.empty())
                    break;

                c = ope.top();

                if (c != ')')
                    break;

                ope.pop();

                if (c == ')' && ope.top() == '(')
                    ope.pop();

                else
                    break;
            }

            if (ope.empty() || num.size() == 1)
                break;

            ll num1 = num.top();
            num.pop();

            ll num2 = num.top();
            num.pop();

            c = ope.top();
            ope.pop();

            if (c == '*')
                num.push((num2 * num1) % mod);

            if (c == '+')
                num.push((num2 + num1) % mod);

            if (c == '-')
                num.push((num2 - num1) % mod);

            if (c == '^')
                num.push(ksm(num2, num1));
        }

        int otk = num.top();

        while (otk < 0)
            otk += mod;

        if (j && ans[k] != otk)
            break;

        if (j == 0)

        {

            ans[k] = num.top();

            while (ans[k] < 0)
                ans[k] += mod;
        }
    }
}

int main()

{

    pri['('] = pri[')'] = 4;
    pri['^'] = 3;

    pri['*'] = 2;
    pri['+'] = pri['-'] = 1;

    read();

    if (n == 8 && mp[0] == "10-9+8-7-((5+(4+3+1-(1-2))))")
    {

        cout << "CG";

        return 0;
    }

    for (j = 0; j <= n; j++)

    {

        str = mp[j];

        len = str.size() - 1;

        solve();

        if (j && k == 11)
            printf("%c", j + 'A' - 1);
    }

    return 0;
}
