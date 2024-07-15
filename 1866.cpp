#include <bits/stdc++.h>

using namespace std;

int main() {
    set<string> cf;
    string f;
    getline(cin, f);
    int cpos = f.find(':');
    string fn = f.substr(0, cpos), kwl = f.substr(cpos + 1, f.length() - cpos - 1), kwt;
    set<string> kw;
    stringstream ss(kwl);
    while (ss >> kwt) {
        kw.insert(kwt);
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        getline(cin, f);
        int tot = 0, pre = 0;
        if (f == "\n" || f.empty()) getline(cin, f);
        cpos = f.find(':');
        fn = f.substr(0, cpos), kwl = f.substr(cpos + 1, f.length() - cpos - 1);
        stringstream ssf(kwl);
        while (ssf >> kwt) {
            tot++;
            if (kw.count(kwt)) pre++;
        }
        cout << fn << ": " << pre << "/" << tot << endl;
    }
    return 0;
}
