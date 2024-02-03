#include <bits/stdc++.h>

using namespace std;

string binCvt(int in) {
    string ans;
    while (in != 0) {
        ans.push_back((in % 2) + '0');
        in /= 2;
    }
    reverse(ans.begin(), ans.end());
    while (ans.length() < 32) {
        ans.insert(0, "0");
    }
    return ans;
}

int tot = 1, ch[2000005][4];


int ins(const string &in) {
    int u = 1;
    for (char c: in) {
        if (!ch[u][c - '0'])
            ch[u][c - '0'] = ++tot;
        u = ch[u][c - '0'];
    }
    return u;
}


string pref(const string &in) {
    string ans;
    int u = 1;
    for (char c: in) { //this will run exactly 32 times
        if (c == '0') {
            //then, prefer 1
            if (ch[u][1]) {
                u = ch[u][1];
                ans.push_back('1');
            } else {
                u = ch[u][0];
                ans.push_back('0');
            }
        } else {
            //prefer 0
            if (ch[u][0]) {
                u = ch[u][0];
                ans.push_back('0');
            } else {
                u = ch[u][1];
                ans.push_back('1');
            }
        }
    }
    return ans;
}

int binPow(int i) {
    if (i == 0) return 1;
    return (2 << (i - 1));
}

int decCvt(string s) {
    int ans = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') {
            ans += binPow(i);
        }
    }
    return ans;
}

vector<int> ind;

int main() {
    int n;
    cin >> n;
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ind.push_back(a);
        ins(binCvt(a));
    }
    for (int a: ind) {
        maxx = max(maxx, decCvt(pref(binCvt(a))) ^ a);
    }
    cout << maxx << endl;
    return 0;
}

