#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 5005;
struct NODE
{
    int v, Next;
} Edges[M];
int Answer[N], Head[N], n, m, DFN[N], Low[M], EdgeCount, SCCCount, Count;
void AddEdge(int u, int v)
{
    Edges[++EdgeCount].v = v;
    Edges[EdgeCount].Next = Head[u];
    Head[u] = EdgeCount;
}
void Tarjan(int u, int Father)
{
    DFN[u] = Low[u] = ++Count;
    int Counter = 0;
    for (int i = Head[u]; i; i = Edges[i].Next)
    {
        int v = Edges[i].v;
        if (v == Father)
            continue;
        if (!DFN[v])
        {
            Counter++;
            Tarjan(v, u);
            Low[u] = min(Low[u], Low[v]);
            if ((Low[v] >= DFN[u] && u != 1) || (u == 1 && Counter > 1))
            {
                Answer[u]++;
                SCCCount++;
            }
        }
        else
            Low[u] = min(Low[u], DFN[v]);
    }
}

int main()
{
    int x, y;
    while (1)
    {
        n++;
        memset(Head, 0, sizeof(Head));
        memset(DFN, 0, sizeof(DFN));
        memset(Low, 0, sizeof(Low));
        memset(Answer, 0, sizeof(Answer));
        memset(Edges, 0, sizeof(Edges));
        EdgeCount = 0;
        Count = 0;
        SCCCount = 0;
        scanf("%d", &x);
        if (x == 0)
            break;
        scanf("%d", &y);
        AddEdge(x, y);
        AddEdge(y, x);
        while (1)
        {
            scanf("%d", &x);
            if (x == 0)
                break;
            scanf("%d", &y);
            AddEdge(x, y);
            AddEdge(y, x);
        }
        for (int i = 1; i <= n; i++)
            if (DFN[i] == 0)
                Tarjan(i, 0);
        printf("Network #%d\n", n);
        if (SCCCount == 0)
            printf("  No SPF nodes\n");
        for (int i = 1; i <= 1000; i++)
            if (Answer[i] > 0)
                printf("  SPF node %d leaves %d subnets\n", i, Answer[i] + 1);
        printf("\n");
    }
    return 0;
}
