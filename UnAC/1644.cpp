#include <bits/stdc++.h>
bool isPrime[10000005];
using namespace std;
void eratos(int n)
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        isPrime[i] = true;
    }
    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    eratos(10000000);
    int cnt = 0, i = 1;
    while (cnt < n)
    {
        i++;
        if (isPrime[i])
        {
            cnt++;
        }
    }
    cout << i << endl;
    return 0;
}
