#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2050000;
ll n, NodeCount, Root, Root1, Root2, Root3, CursorPosition;
stack<ll> Stack;
char s[N];
struct NODE
{
    ll Size, Rand, LeftChild, RightChild;
    char Value;
} Nodes[N];
void Output(ll x)
{
    if (Nodes[x].LeftChild)
        Output(Nodes[x].LeftChild);
    printf("%c", Nodes[x].Value);
    if (Nodes[x].RightChild)
        Output(Nodes[x].RightChild);
}
void PushUp(ll x)
{
    Nodes[x].Size = Nodes[Nodes[x].LeftChild].Size + Nodes[Nodes[x].RightChild].Size + 1;
}
ll NewNode(char Value)
{
    Nodes[++NodeCount].Value = Value;
    Nodes[NodeCount].Size = 1;
    Nodes[NodeCount].Rand = rand();
    return NodeCount;
}
void Spilt(ll x, ll k, ll &a, ll &b)
{
    if (!x)
    {
        a = b = 0;
        return;
    }
    if (k <= Nodes[Nodes[x].LeftChild].Size)
    {
        b = x;
        Spilt(Nodes[x].LeftChild, k, a, Nodes[x].LeftChild);
    }
    else
    {
        a = x;
        Spilt(Nodes[x].RightChild, k - Nodes[Nodes[x].LeftChild].Size - 1, Nodes[x].RightChild, b);
    }
    PushUp(x);
}
ll Merge(ll x, ll y)
{
    if (x == 0 || y == 0)
        return x + y;
    if (Nodes[x].Rand < Nodes[y].Rand)
    {
        Nodes[x].RightChild = Merge(Nodes[x].RightChild, y);
        PushUp(x);
        return x;
    }
    else
    {
        Nodes[y].LeftChild = Merge(x, Nodes[y].LeftChild);
        PushUp(y);
        return y;
    }
}
ll Build(ll Length)
{
    for (ll i = 1; i <= Length; i++)
    {
        ll Temp = NewNode(s[i]);
        ll Last = 0;
        while (!Stack.empty() && Nodes[Stack.top()].Rand > Nodes[Temp].Rand)
        {
            PushUp(Stack.top());
            Last = Stack.top();
            Stack.pop();
        }
        if (!Stack.empty())
            Nodes[Stack.top()].RightChild = Temp;
        Nodes[Temp].LeftChild = Last;
        Stack.push(Temp);
    }
    while (Stack.size() > 1)
        PushUp(Stack.top()), Stack.pop();
    return Stack.top();
}
void Insert(ll x)
{
    Spilt(Root, CursorPosition, Root1, Root3);
    for (ll i = 1; i <= x; i++)
    {
        char Children = getchar();
        while (Children == 10 || Children == 13 || Children < 32 || Children > 126)
            Children = getchar();
        s[i] = Children;
    }
    while (!Stack.empty())
        Stack.pop();
    ll Root2 = Build(x);
    Root = Merge(Root1, Merge(Root2, Root3));
}
void Delete(ll x)
{
    Spilt(Root, CursorPosition + x, Root1, Root3);
    Spilt(Root1, CursorPosition, Root1, Root2);
    Root = Merge(Root1, Root3);
}
void Get(ll x)
{
    Spilt(Root, CursorPosition + x, Root1, Root3);
    Spilt(Root1, CursorPosition, Root1, Root2);
    Output(Root2);
    printf("\n");
    Root = Merge(Root1, Merge(Root2, Root3));
}
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        char Operation[10];
        scanf("%s", Operation);
        if (Operation[0] == 'M')
            scanf("%lld", &CursorPosition);
        if (Operation[0] == 'I')
        {
            ll x;
            scanf("%lld", &x);
            Insert(x);
        }
        if (Operation[0] == 'D')
        {
            ll x;
            scanf("%lld", &x);
            Delete(x);
        }
        if (Operation[0] == 'G')
        {
            ll x;
            scanf("%lld", &x);
            Get(x);
        }
        if (Operation[0] == 'P')
            CursorPosition--;
        if (Operation[0] == 'N')
            CursorPosition++;
    }
    return 0;
}
