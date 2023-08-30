#include <bits/stdc++.h>
using namespace std;
vector<int> heap = {-1};
#define ot cout << heap[1] << endl
int heapSize = 0;
void up(int k)
{
    while (k > 1)
    {
        int i = k / 2;
        if (heap[i] > heap[k])
            swap(heap[i], heap[k]);
        else
            break;
        k = i;
    }
}
void down(int k)
{
    while (k + k <= heapSize)
    {
        int i = k + k;
        if (i + 1 <= heapSize && heap[i + 1] < heap[i])
            i++;
        if (heap[i] < heap[k])
        {
            swap(heap[i], heap[k]);
            k = i;
        }
        else
            break;
    }
}
void del(int pos)
{
    swap(heap[pos], heap[heapSize]);
    heapSize--;
    up(pos);
    down(pos);
}
void ins(int val)
{
    heapSize++;
    if (heap.size() < heapSize + 1)
        heap.resize(heapSize + 2);
    heap[heapSize] = val;
    up(heapSize);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        char c;
        c = getchar();
        while (c == '\n' || c == ' ')
            c = getchar();
        switch (c)
        {
        case 'a':
        {
            int t;
            scanf("%d", &t);
            ins(t);
            break;
        }
        case 'q':
        {
            printf("%d\n", heap[1]);
            del(1);
            break;
        }
        default:
        {
            abort();
        }
        }
    }
    return 0;
}
