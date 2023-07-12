#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, w;
class BigNumber
{
private:
    unsigned char Data[205] = {0};
    unsigned char Length = 0;

public:
    BigNumber() {}
    BigNumber(ll x)
    {
        while (x)
        {
            Data[Length] = x % 10;
            x /= 10;
            Length++;
        }
    }
    void Print()
    {
        for (ll i = Length - 1; i >= 0; i--)
            printf("%d", Data[i]);
        printf("\n");
    }
    BigNumber operator+(BigNumber x)
    {
        BigNumber Answer;
        Answer.Length = max(Length, x.Length);
        for (ll i = 0; i < Answer.Length; i++)
        {
            Answer.Data[i] += Data[i] + x.Data[i];
            if (Answer.Data[i] >= 10)
            {
                Answer.Data[i] -= 10;
                Answer.Data[i + 1]++;
            }
        }
        if (Answer.Data[Answer.Length] != 0)
            Answer.Length++;
        return Answer;
    }
    void operator+=(BigNumber x)
    {
        *this = *this + x;
    }
};
ll C(ll n, ll m)
{
    ll Answer = 1;
    for (ll i = 1; i <= m; i++)
        Answer *= (n - i);
    for (ll i = 2; i <= m; i++)
        Answer = Answer / i;
    return Answer;
}
int main()
{
    // freopen("digital.in", "r", stdin);
    // freopen("digital.out", "w", stdout);
    scanf("%lld%lld", &k, &w);
    ll Max = pow(2, k);
    ll Wei = w / k + 1;
    ll High = min((ll)pow(2, w % k) - 1, Max - Wei);
    BigNumber Answer;
    for (ll i = 2; i < Wei; i++)
        Answer += C(Max, i);
    if (High != 0)
        Answer += C(Max, Wei) - C(Max - High, Wei);
    Answer.Print();
    return 0;
}
