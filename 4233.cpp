#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n, a[N], Answer;
void BubbleSort()
{
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        Answer++;
        for (ll i = 0; i < n - 1; i++)
            if (a[i + 1] < a[i])
                swap(a[i], a[i + 1]);
        for (ll i = n - 2; i >= 0; i--)
            if (a[i + 1] < a[i])
                swap(a[i], a[i + 1]);
        for (ll i = 0; i < n - 1; i++)
            if (a[i + 1] < a[i])
                sorted = false;
    }
}
int main()
{
    freopen("bsort.in", "r", stdin);
    freopen("bsort.out", "w", stdout);
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    BubbleSort();
    printf("%lld\n", Answer);
    return 0;
}
