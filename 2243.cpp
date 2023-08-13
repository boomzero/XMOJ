#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int M = 20000005;
struct
{
    int Next, Size;
    char a[N * 2];
} Block[N * 4];
int Pool[N * 4], PoolCount, Cursor;
int Pop()
{
    PoolCount++;
    return Pool[PoolCount - 1];
}
void Insert(int x)
{
    PoolCount--;
    Pool[PoolCount] = x;
}
void Add(int x, int y, int Number, char c[])
{
    if (y != -1)
    {
        Block[y].Next = Block[x].Next, Block[y].Size = Number;
        memcpy(Block[y].a, c, Number);
    }
    Block[x].Next = y;
}
void Merge(int x, int y)
{
    memcpy(Block[x].a + Block[x].Size, Block[y].a, Block[y].Size);
    Block[x].Size += Block[y].Size, Block[x].Next = Block[y].Next;
    Insert(y);
}
void Spilt(int Current, int Position)
{
    if (Current == -1 || Position == Block[Current].Size)
        return;
    Add(Current, Pop(), Block[Current].Size - Position, Block[Current].a + Position);
    Block[Current].Size = Position;
}
int Position(int &x)
{
    int Now = 0;
    while (Now != -1 && x > Block[Now].Size)
    {
        x -= Block[Now].Size;
        Now = Block[Now].Next;
    }
    return Now;
}
void Insert(string s)
{
    int Number = s.size();
    char *c = new char[Number];
    for (int i = 0; i < Number; i++)
        c[i] = s[i];
    int Now = Position(Cursor);
    Spilt(Now, Cursor);
    int tot = 0, nb, st = Now;
    while (tot + N <= Number)
    {
        nb = Pop();
        Add(Now, nb, N, c + tot);
        tot += N;
        Now = nb;
    }
    if (Number - tot)
        nb = Pop(), Add(Now, nb, Number - tot, c + tot);
    if (Block[Now].Size + Block[nb].Size < N && nb != -1)
        Merge(Now, nb), nb = Block[Now].Next;
    if (Block[st].Size + Block[Block[st].Next].Size < N && Block[st].Next != -1)
        Merge(st, Block[st].Next);
}
void Erase(int Number)
{
    int Now = Position(Cursor);
    Spilt(Now, Cursor);
    int Next = Block[Now].Next;
    while (Next != -1 && Number > Block[Next].Size)
        Number -= Block[Next].Size, Next = Block[Next].Next;
    Spilt(Next, Number);
    Next = Block[Next].Next;
    for (int i = Block[Now].Next; i != Next; i = Block[Now].Next)
        Block[Now].Next = Block[i].Next, Insert(i);
    while (Block[Now].Size + Block[Next].Size < N && Next != -1)
        Merge(Now, Next), Next = Block[Now].Next;
}
string Get(int Number)
{
    char Answer[M];
    int cur = Position(Cursor);
    int tot = Block[cur].Size - Cursor;
    if (Number < tot)
        tot = Number;
    memcpy(Answer, Block[cur].a + Cursor, tot);
    int Now = Block[cur].Next;
    while (Now != -1 && Number >= tot + Block[Now].Size)
    {
        memcpy(Answer + tot, Block[Now].a, Block[Now].Size);
        tot += Block[Now].Size, Now = Block[Now].Next;
    }
    if (Number - tot > 0 && Now != -1)
        memcpy(Answer + tot, Block[Now].a, Number - tot);
    Answer[Number] = '\0';
    return Answer;
}
int main()
{
    for (int i = 1; i < N * 4; ++i)
        Pool[i] = i;
    PoolCount = 1;
    Block[0].Size = 0, Block[0].Next = -1;
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        char Buffer[7];
        scanf("%s", Buffer);
        string Operation = Buffer;
        if (Operation == "Move")
            scanf("%d", &Cursor);
        else if (Operation == "Insert")
        {
            int x;
            scanf("%d", &x);
            char Answer[M];
            for (int i = 0; i < x; ++i)
            {
                Answer[i] = getchar();
                if (Answer[i] < 32 || Answer[i] > 126)
                    --i;
            }
            string s = Answer;
            Insert(s);
        }
        else if (Operation == "Insert")
        {
            int x;
            scanf("%d", &x);
            Erase(x);
        }
        else if (Operation == "Get")
        {
            int x;
            scanf("%d", &x);
            Get(x);
        }
        else if (Operation == "Prev")
            Cursor--;
        else if (Operation == "Next")
            Cursor++;
    }
    return 0;
}
