#include <bits/stdc++.h>

using namespace std;

int main() {
    int c;
    cin >> c;
    deque<int> q;
    for (int i = 0; i < c; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "PUSH") {
            int x;
            cin >> x;
            q.push_back(x);
        } else if (cmd == "POP-BACK") {
            if (q.empty()) {
                cout << "error" << endl;
            } else {
                cout << q.back() << endl;
                q.pop_back();
            }
        } else {
            if (q.empty()) {
                cout << "error" << endl;
            } else {
                cout << q.front() << endl;
                q.pop_front();
            }
        }
    }
    if (q.empty()) cout << "empty" << endl;
    else {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop_front();
        }
        cout << endl;
    }
    return 0;
}

