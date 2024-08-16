#include <bits/stdc++.h>

using namespace std;
set<int> h;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char c;
        c = getchar();
        while (c == '\n' || c == ' ')
            c = getchar();
        switch (c) {
            case 'a': {
                int t;
                scanf("%d", &t);
                h.insert(t);
                break;
            }
            case 'q': {
                printf("%d\n", *h.begin());
                h.erase(h.begin());
                break;
            }
            case 'd': {
                int t;
                scanf("%d", &t);
                h.erase(t);
                break;
            }
            default: {
            }
        }
    }
    return 0;
}

