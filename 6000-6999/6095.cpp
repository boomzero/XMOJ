#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;
typedef unsigned long long ull;
const int maxtot = 20005;
const int maxm = 4e6+5;
const int base = 131;
const int mod = 19260817;
string S[maxtot], T[maxtot];
int totalT, totalS, n, m;
int mid;
ull Pow[maxm];
unordered_map<ull,int> hashT;
ull Hash[maxm];
int cnt[mod];

ull qmi(ull a,ull b){
    ull res = 1;
    while (b){
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ull make_hash(string s, int len){
    ull res = 0;
    for (int i = 0; i < len; i ++){
        res = res*base + s[i];
    }
    return res;
}

ull get_hash(int l,int r){
    return Hash[r] - Hash[l-1]*Pow[r-l+1];
}

int deal(string s, int len, int t){
    int res = 0, length = len-mid;
    string temp = "0";
    temp += s.substr(0,mid);
    temp += s.substr(0,mid);
    for (int i = 1; i <= mid<<1; i ++){
        Hash[i] = Hash[i-1]*base + temp[i];
    }
    ull hashVal = make_hash(s.substr(mid,len-mid), len-mid);

    for (int i = 1, j = mid; i <= mid; i ++, j ++){
        if (cnt[get_hash(i, j)%mod] == t){
            continue;
        }
        cnt[get_hash(i, j)%mod] = t;
        if (get_hash(i, i+length-1) == hashVal){
            res += hashT[get_hash(i+length, j)];
        }
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> totalS >> totalT >> n >> m;
    for (int i = 1; i <= totalS; i ++){
        cin >> S[i];
    }
    for (int i = 1; i <= totalT; i ++){
        cin >> T[i];
    }
    mid = (n+m) >> 1;
    Pow[mid] = qmi(base,mid), Pow[m] = qmi(base,m), Pow[(n-m)>>1] = qmi(base,(n-m)>>1);
    for (int i = 1; i <= totalT; i ++){
        hashT[make_hash(T[i], m)] ++;
    }

    int ans = 0;
    for (int i = 1; i <= totalS; i ++){
        ans += deal(S[i], n, i);
    }

    cout << ans << endl;
    return 0;
}
