#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'D': {
                char x;
                cin >> x;
                int pos = s.find(x);
                if (pos != -1)
                    s.erase(pos, 1);
                cout << s << endl;
                break;
            }
            case 'I': {
                char x;
                string y;
                cin >> x >> y;
                int pos = -1;
                for (int j = s.length() - 1; j >= 0; --j) {
                    if (s[j] == x) {
                        pos = j;
                        break;
                    }
                }
                if (pos != -1) {
                    s.insert(pos, y);
                }
                cout << s << endl;
                break;
            }
            case 'R': {
                char x;
                string y;
                cin >> x >> y;
                int pos = -1;
                for (int j = s.length() - 1; j >= 0; --j) {
                    if (s[j] == x) {
                        pos = j;
                        s.replace(pos, 1, y);
                    }
                }
                if (pos != -1) {
                    cout << s << endl;
                } else {
                    cout << "Not found" << endl;
                }
                break;
            }
        }
    }
    return 0;
}


