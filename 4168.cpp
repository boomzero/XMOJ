#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n, s, SegmentID[N], Answer;
struct NOTE
{
    ll Day, ID, Delta;
} a[N];
struct SEGMENT
{
    ll Value, Left, Right, Count;
} Segments[N * 2];
void Build(ll Index, ll Left, ll Right)
{
    Segments[Index].Value = s;
    Segments[Index].Left = Left;
    Segments[Index].Right = Right;
    Segments[Index].Count = Right - Left + 1;
    if (Left != Right)
    {
        ll Middle = (Left + Right) / 2;
        Build(Index * 2, Left, Middle);
        Build(Index * 2 + 1, Middle + 1, Right);
    }
    else
        SegmentID[a[Left].ID] = Index;
}
void Modify(ll Index, ll Delta)
{
    Segments[Index].Value += Delta;
    while (Index > 1)
    {
        Index /= 2;
        if (Segments[Index * 2].Value > Segments[Index * 2 + 1].Value)
        {
            Segments[Index].Value = Segments[Index * 2].Value;
            Segments[Index].Count = Segments[Index * 2].Count;
        }
        else if (Segments[Index * 2].Value < Segments[Index * 2 + 1].Value)
        {
            Segments[Index].Value = Segments[Index * 2 + 1].Value;
            Segments[Index].Count = Segments[Index * 2 + 1].Count;
        }
        else
        {
            Segments[Index].Value = Segments[Index * 2].Value;
            Segments[Index].Count = Segments[Index * 2].Count + Segments[Index * 2 + 1].Count;
        }
        // cout << "Segments[" << Index << " /*" << Segments[Index].Left << "~" << Segments[Index].Right << "*/].Value = max(";
        // cout << "Segments[" << (Index * 2) << " /*" << Segments[Index * 2].Left << "~" << Segments[Index * 2].Left << "*/].Value, ";
        // cout << "Segments[" << (Index * 2 + 1) << " /*" << Segments[Index * 2 + 1].Left << "~" << Segments[Index * 2 + 1].Left << "*/].Value);" << endl;
        // cout << "                          = max(" << Segments[Index * 2].Value << ", " << Segments[Index * 2 + 1].Value << ");" << endl;
        // cout << "                          = " << max(Segments[Index * 2].Value, Segments[Index * 2 + 1].Value) << endl;
    }
}
pair<ll, ll> Query()
{
    return {Segments[1].Value, Segments[1].Count};
}
int main()
{
    scanf("%lld%lld", &n, &s);
    for (ll i = 1; i <= n; i++)
        scanf("%lld%lld%lld", &a[i].Day, &a[i].ID, &a[i].Delta);
    sort(a + 1, a + n + 1,
         [](NOTE a, NOTE b)
         {
             return a.Day < b.Day;
         });
    Build(1, 1, n);
    // cout << "Max number: " << Query().first << "  Max count: " << Query().second << endl;
    pair<ll, ll> LastData = Query();
    for (ll i = 1; i <= n; i++)
    {
        ll Index = SegmentID[a[i].ID];
        // cout << "SegmentID[" << a[i].ID << "] = " << Index << endl;
        Modify(Index, a[i].Delta);
        pair<ll, ll> Data = Query();
        if (Data != LastData)
        {
            LastData = Data;
            Answer++;
        }
        // cout << "Max number: " << Query().first << "  Max count: " << Query().second << endl;
        // cout << endl;
    }
    printf("%lld\n", Answer);
    return 0;
}
/*
4 10
7 3 +3
4 2 -1
9 3 -1
1 1 +2

   |
   |  Sort
   V

4 10
1 1 +2
4 2 -1
7 3 +3
9 3 -1

   |
   |  Run
   V

    People
   1   2   3
S  10  10  10
c  12  10  10
o  12  9   10
r  12  9   13
e  12  9   12

*/
