#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
priority_queue<unsigned long long, vector<ull>, greater<>> un;

unsigned long long pow(int a, int b) {
    unsigned long long ans = 1;
    for (unsigned long long i = 0; i < b; ++i) {
        ans *= a;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    un.push(1);
    int i = 0;
    while (true) {
        ull prev;
        prev = un.top();
        i++;
        if (i == n) {
            cout << prev << endl;
            break;
        }
        while (!un.empty() && prev == un.top()) {
            un.pop();
        }
        un.push(prev * 2);
        un.push(prev * 3);
        un.push(prev * 5);
        un.push(prev * 7);
    }
    return 0;
}

