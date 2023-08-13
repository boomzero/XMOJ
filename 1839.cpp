#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tLength, sLength, Answer;
string t, s;
map<char, ll> tMap, sMap;
int main()
{
    scanf("%lld%lld", &tLength, &sLength);
    cin >> t >> s;
    for (ll i = 0; i < tLength; i++)
        tMap[t[i]]++;
    for (ll i = 0; i < tLength; i++)
        sMap[s[i]]++;
    for (ll i = tLength; i < sLength; i++)
    {
        if (tMap == sMap)
            Answer++;
        sMap[s[i]]++;
        sMap[s[i - tLength]]--;
        if (sMap[s[i - tLength]] == 0)
            sMap.erase(s[i - tLength]);
    }
    if (tMap == sMap)
        Answer++;
    printf("%lld\n", Answer);
    return 0;
}
