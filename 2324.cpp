#include <bits/stdc++.h>

using namespace std;

struct ip {
    int num, val;

    bool operator<(const ip &rhs) const {
        if (num > rhs.num)
            return true;
        if (rhs.num > num)
            return false;
        return val < rhs.val;
    }

    bool operator>(const ip &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const ip &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const ip &rhs) const {
        return !(*this < rhs);
    }
};

priority_queue<ip> p;

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
                int t, val;
                scanf("%d%d", &t, &val);
                ip tmp = {t, val};
                p.push(tmp);
                break;
            }
            case 'q': {
                printf("%d %d\n", p.top().num,p.top().val);
                p.pop();
                break;
            }
            default: {
                abort();
            }
        }
    }
    return 0;
}


