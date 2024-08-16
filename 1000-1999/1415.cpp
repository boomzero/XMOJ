#include <bits/stdc++.h>

using namespace std;
int n[5] = {0}, ans = 0;
bool vis[5] = {false};
int num[5] = {0}, rst[5] = {0};
char uop[5] = {0};
int stackSize = 0;
bool solved = false;

void dfs(int op, int c) {  /// 1+ 2- 3* 4/
    char cop;
    auto getOp = [](int in) -> char {
        switch (in) {
            case 1:
                return '+';
            case 2:
                return '-';
            case 3:
                return '*';
            case 4:
                return '/';
            default:
                assert(false);
        }
    };
    cop = getOp(op);
    stackSize++;
    uop[stackSize] = cop;
    num[stackSize] = n[c];
    op == 1 ? ans += n[c] : op == 2 ? ans -= n[c] : op == 3 ? ans *= n[c] : ans /= n[c];
    rst[stackSize] = ans;
    vis[c] = true;
    if (ans == 24 && stackSize == 4) {
        solved = true;
        cout << num[1] << uop[2] << num[2] << '=' << rst[2] << endl;
        cout << rst[2] << uop[3] << num[3] << '=' << rst[3] << endl;
        cout << rst[3] << uop[4] << num[4] << '=' << rst[4] << endl;
    } else if (!solved) {
        for (int i = 1; i <= 4; ++i) {
            if (!vis[i]) {
                for (int j = 1; j <= 4; ++j) {
                    if (j == 4 && ans / n[i] * n[i] != ans) continue;
                    if (j == 2 && ans - n[i] < 0) continue;
                    dfs(j, i);
                }
            }
        }
    }
    vis[c] = false;
    op == 1 ? ans -= n[c] : op == 2 ? ans += n[c] : op == 3 ? ans /= n[c] : ans *= n[c];
    stackSize--;
}

int main() {
    for (int i = 1; i <= 4; ++i) {
        cin >> n[i];
    }
    for (int i = 1; i <= 4; ++i) {
        if (!vis[i]) {
            dfs(1, i);
        }
    }
    if (!solved) cout << "No answer!" << endl;
    return 0;
}
