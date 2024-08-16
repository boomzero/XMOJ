#include <iostream>
using namespace std;
int L, N, M;
int sz[50010];
bool judge(int mid)
{
    int m = 0, before = sz[0];
    for (int i = 1; i <= N + 1; ++i)
    {
        if (sz[i] - before < mid)
        {
            m++;
        }
        else
        {
            before = sz[i];
        }
    }
    return (m <= M);
}
int main()
{
    cin >> L >> N >> M;
    int left = 0, right = L + 1;
    sz[0] = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> sz[i];
    }
    sz[N + 1] = L;
    while (left < right)
    {
        int mid = (left + right + 1) / 2;
        if (judge(mid))
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << left;
}
