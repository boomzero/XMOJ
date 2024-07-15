#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int n;
vector<string> num;

int main() {
//    try {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end(), cmp);
    for (string p: num) {
        cout << p;
    }
    cout << endl;
//    } catch (exception e) {
//        string em = to_string(n);
//        em.push_back(' ');
//        for (string p: num) {
//            em.append(p);
//            em.push_back(' ');
//        }
//        throw runtime_error(em);
//    }
    return 0;
}

