#include <bits/stdc++.h>
using namespace std;
long long ans[41][7];
int n, m;
char s[50];
long long str2int(char s[], int l, int r)
{
    long long answer = 0;
    for (int i = l; i <= r; ++i)
        answer = answer * 10 + s[i] - '0';
    return answer;
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i)
        ans[i][0] = str2int(s, 0, i - 1);
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= min(i - 1, m); ++j)
        {
            for (int k = j; k <= i - 1; ++k)
            {
                long long tmp = str2int(s, k, i - 1) * ans[k][j - 1];
                if (ans[i][j] < tmp)
                    ans[i][j] = tmp;
            }
        }
    }
    cout << ans[n][m] << endl;
}
