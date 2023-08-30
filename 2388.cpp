#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 305;
const ll M = 1005;
ll Total, n, a[N];
class BigNumber
{
private:
    short Data[105] = {0};
    short Length = 0;
public:
    BigNumber()
    {
        memset(Data, 0, sizeof(Data));
        Length = 0;
    }
    BigNumber(ll x)
    {
        memset(Data, 0, sizeof(Data));
        while (x)
        {
            Data[Length] = x % 10;
            x /= 10;
            Length++;
        }
    }
    void Print()
    {
        if (Length == 0)
            printf("0");
        for (ll i = Length - 1; i >= 0; i--)
            printf("%d", Data[i]);
        printf("\n");
    }
    friend BigNumber operator+(BigNumber x, BigNumber y);
    void operator+=(BigNumber x)
    {
        *this = *this + x;
    }
};
BigNumber operator+(BigNumber x, BigNumber y)
{
    BigNumber Answer;
    Answer.Length = max(x.Length, y.Length);
    for (ll i = 0; i < Answer.Length; i++)
    {
        Answer.Data[i] += x.Data[i] + y.Data[i];
        while (Answer.Data[i] >= 10)
        {
            Answer.Data[i] -= 10;
            Answer.Data[i + 1]++;
        }
    }
    if (Answer.Data[Answer.Length] != 0)
        Answer.Length++;
    return Answer;
}
BigNumber f[N][M];
int main()
{
    scanf("%lld%lld", &Total, &n);
    for (ll i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    f[0][0] = 1;
    for (ll i = 0; i <= n; i++)
        f[i][0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= Total; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= a[i - 1])
                f[i][j] += f[i][j - a[i - 1]];
        }
    f[n][Total].Print();
    return 0;
}
