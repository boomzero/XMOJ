#include <bits/stdc++.h>

using namespace std;
map<string, int> sid;

bool check(string in, int max) {
    if (in[0] == '0' && in.length() > 1) {
        return false;
    }
    int conv = stoi(in);
    return conv <= max;
}

bool isNumber(string in) {
    for (char i: in) {
        if (!isdigit(i)) return false;
    }
    return true;
}

bool check(string in) {
    try {
        int pos, lloc = 0;
        string seg;
        pos = in.find('.');
        if (pos == string::npos) {
            return false;
        }
        seg = in.substr(lloc, pos - lloc);
        if (!isNumber(seg) || seg.length() == 0) return false;
        lloc = pos + 1;
        //clog << seg << endl;
        if (!check(seg, 255)) return false;
        in[pos] = '/';
        //again
        pos = in.find('.');
        if (pos == string::npos) {
            return false;
        }
        seg = in.substr(lloc, pos - lloc);
        if (!isNumber(seg) || seg.length() == 0) return false;
        lloc = pos + 1;
        //clog << seg << endl;
        if (!check(seg, 255)) return false;
        in[pos] = '/';
        //again
        pos = in.find('.');
        if (pos == string::npos) {
            return false;
        }
        seg = in.substr(lloc, pos - lloc);
        if (!isNumber(seg) || seg.length() == 0) return false;
        lloc = pos + 1;
        //clog << seg << endl;
        if (!check(seg, 255)) return false;
        in[pos] = '/';
        //again
        pos = in.find(':');
        if (pos == string::npos) {
            return false;
        }
        seg = in.substr(lloc, pos - lloc);
        if (!isNumber(seg) || seg.length() == 0) return false;
        lloc = pos + 1;
        //clog << seg << endl;
        if (!check(seg, 255)) return false;
        in[pos] = '/';
        //the rest
        seg = in.substr(lloc, in.length() - lloc);
        if (!isNumber(seg) || seg.length() == 0) return false;
        //clog << seg << endl;
        if (!check(seg, 65535)) return false;
        return true;
    } catch (exception &e) {
        return false; //contains non-numerical characters
    }
}

int main() {
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string stat, in;
        cin >> stat >> in;
        if (!check(in)) {
            cout << "ERR" << endl;
            continue;
        }
        if (stat == "Server") {
            if (sid.count(in)) {
                cout << "FAIL" << endl;
            } else {
                sid[in] = i;
                cout << "OK" << endl;
            }
        } else {
            if (sid.count(in)) {
                cout << sid[in] << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}

