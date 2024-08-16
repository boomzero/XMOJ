#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200005;
const ll INF = 0x3FFF'FFFF'FFFF'FFFF;
string s;
ll Last[26], f[N], Next[N];
char Memory[N];
int main()
{
    freopen("substr.in", "r", stdin);
    freopen("substr.out", "w", stdout);
    char Buffer[N] = {0};
    scanf("%s", Buffer + 1);
    Buffer[0] = ' ';
    for (ll i = 0; i < 26; i++)
        Last[i] = strlen(Buffer);
    s = Buffer;
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        f[i] = INF;
        for (ll j = 0; j < 26; j++)
            if (f[i] > f[Last[j]] + 1)
            {
                f[i] = f[Last[j]] + 1;
                Next[i] = Last[j];
                Memory[i] = 'a' + j;
            }
        if (i != 0)
            Last[s[i] - 'a'] = i;
    }
    for (ll i = 0; f[i]; i = Next[i])
        printf("%c", Memory[i]);
    printf("\n");
    return 0;
}
