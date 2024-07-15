#include <bits/stdc++.h>

#define end (s.length() - 1)
using namespace std;
string s;

int main() {
    freopen("order.in", "r", stdin);
    freopen("order.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char x;
        cin >> x;
        s.push_back(x);
    }
    int p=0;
    while (!s.empty()) {
    p++;
        if (s[0] < s[end]) {
            cout << s[0];
            s.erase(s.begin());
        } else if (s[0] > s[end]) {
            cout << s[end];
            s.erase(end, 1);
        } else {
            int l = 0, r = end;
            bool done = false;
            while (l < r) {
                l++;
                r--;
                if (s[l] < s[r]) {
                    cout << s[0];
                    s.erase(s.begin());
                    done = true;
                    break;
                } else if (s[l] > s[r]) {
                    cout << s[end];
                    s.erase(end, 1);
                    done = true;
                    break;
                }
            }
            if (!done) {
                cout << s[0];
                s.erase(s.begin());
            }
    
        }
        if(p==80){ p=0; cout<<'\n';
            }
    }
    cout << endl;
    return 0;
}

