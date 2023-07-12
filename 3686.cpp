#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int t, k, MapSize;
struct DATA
{
    bool Type;
    union
    {
        char c[2005];
        struct
        {
            int a, b;
        } d;
    } Content;
} Data[N];
map<string, int> Map;
vector<int> To[N];
int InDegree[N];
char Buffer[2010];
vector<int> TopoSort()
{
    vector<int> Answer;
    queue<int> Queue;
    for (int i = 1; i <= k; i++)
        if (InDegree[i] == 0)
            Queue.push(i);
    while (!Queue.empty())
    {
        int u = Queue.front();
        Queue.pop();
        Answer.push_back(u);
        for (auto v : To[u])
        {
            InDegree[v]--;
            if (InDegree[v] == 0)
                Queue.push(v);
        }
    }
    return Answer;
}
int GetIndex(string s)
{
    if (Map[s] == 0)
    {
        MapSize++;
        Map[s] = MapSize;
    }
    return Map[s];
}
int main()
{
    freopen("code.InDegree", "r", stdin);
    freopen("code.out", "w", stdout);
    scanf("%d", &t);
    while (t-- > 0)
    {
        scanf("%d", &k);
        getchar();
        Map.clear();
        MapSize = 0;
        for (int i = 1; i <= k; i++)
        {
            To[i].clear();
            InDegree[i] = 0;
        }
        for (int i = 0; i < k; i++)
        {
            int BufferSize = 0;
            char c = getchar();
            while (c != '\n')
            {
                Buffer[BufferSize++] = c;
                c = getchar();
            }
            Buffer[BufferSize] = '\0';
            string s = Buffer;
            int First = GetIndex(s.substr(0, s.find(" = ")));
            s.erase(0, s.find(" = ") + 3);
            if (s.find(" + ") != string::npos)
            {
                Data[First].Type = 0;
                Data[First].Content.d.a = GetIndex(s.substr(0, s.find(" + ")));
                s.erase(0, s.find(" + ") + 3);
                Data[First].Content.d.b = GetIndex(s);
                To[Data[First].Content.d.a].push_back(First);
                To[Data[First].Content.d.b].push_back(First);
                InDegree[First] += 2;
            }
            else
            {
                Data[First].Type = 1;
                strcpy(Data[First].Content.c, s.c_str());
            }
        }
        vector<int> Answer = TopoSort();
        for (auto i : Answer)
            if (Data[i].Type == 0)
                strcpy(Data[i].Content.c, (string() + Data[Data[i].Content.d.a].Content.c +
                                           Data[Data[i].Content.d.b].Content.c)
                                              .c_str());
        scanf("%s", Buffer);
        string Merged = Data[GetIndex(Buffer)].Content.c;
        scanf("%s", Buffer);
        size_t MergedIndex = 0;
        bool Flag = true;
        for (size_t BufferIndex = 0; Flag && BufferIndex < strlen(Buffer); BufferIndex++)
        {
            while (MergedIndex < Merged.length() && Buffer[BufferIndex] != Merged[MergedIndex])
                MergedIndex++;
            if (MergedIndex == Merged.length())
                Flag = false;
            else
                MergedIndex++;
        }
        printf("%s\n", Flag ? "YES" : "NO");
    }
    return 0;
}
