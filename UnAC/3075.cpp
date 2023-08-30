#include <bits/stdc++.h>
using namespace std;
int n;
bool isSorted(const vector<int> &sequence)
{
    for (int i = 1; i < sequence.size(); i++)
        if (sequence[i] < sequence[i - 1])
            return false;
    return true;
}
int findMinX(vector<int> &sequence)
{
    int minX = 0;
    while (true)
    {
        for (int i = 0; i < sequence.size(); i++)
            sequence[i] ^= minX;
        sort(sequence.begin(), sequence.end());
        bool flag = isSorted(sequence);
        for (int i = 0; i < sequence.size(); i++)
            sequence[i] ^= minX;
        if (flag)
            return minX;
        minX++;
        if (minX > 1000000)
            return -1;
    }
    return minX;
}
int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; i++)
        cin >> sequence[i];
    cout << findMinX(sequence) << endl;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        sequence[x - 1] = y;
        cout << findMinX(sequence) << endl;
    }
    return 0;
}
