#include <bits/stdc++.h>

using namespace std;
int xs, ys, xt, yt, dx, dy;
int sp[5][5] = {{0, 3, 2, 3, 2},
                {3, 2, 1, 2, 3},
                {2, 1, 4, 3, 2},
                {3, 2, 3, 2, 3},
                {2, 3, 2, 3, 4}};

int main() {
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    cin >> xs >> ys >> xt >> yt;
    dx = abs(xs - xt);
    dy = abs(ys - yt);
    int ans = 0;
    while (dx > 4 || dy > 4) {
        if (dx > dy) {
            dx -= 2;
            dy -= 1;
        } else {
            dx -= 1;
            dy -= 2;
        }
        dx = abs(dx);
        dy = abs(dy);
        ans++;
    }
    cout << sp[dx][dy] + ans << endl;
    return 0;
}

