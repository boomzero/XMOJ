#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
int n11, n21, g11[MAXN][2], g21[MAXN][2];
bool gameover(int a, int b, int n)
{
        if (abs(a - b) < 2)
                return false;
        if (a >= n || b >= n)
                return true;
        return false;
}
void proc(char ch, int n, int g[][2], int &cnt)
{
        if (ch == 'W')
                g[cnt][0]++;
        else
                g[cnt][1]++;
        if (gameover(g[cnt][0], g[cnt][1], n))
                ++cnt;
}
void print(int cnt, int g[][2])
{
        for (int i = 0; i <= cnt; ++i)
                cout << g[i][0] << ':' << g[i][1] << endl;
}
int main()
{
        while (1)
        {
                char ch = getchar();
                if (ch == 'E')
                        break;
                if (ch == 'W' || ch == 'L')
                {
                        proc(ch, 11, g11, n11);
                        proc(ch, 21, g21, n21);
                }
        }
        print(n11, g11);
        cout << endl;
        print(n21, g21);
        return 0;
}
