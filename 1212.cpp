#include <bits/stdc++.h>
#define cc grid[get<1>(c)][get<2>(c)]
using namespace std;
int grid[1500][1500] = {{0}}, dist[1500][1500] = {{0}};
int xm[] = {1, -1, 0, 0}, ym[] = {0, 0, 1, -1};
int main() {
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int m, n;
    cin >> m >> n;
    memset(grid, -1, sizeof(grid));
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        grid[x][y] = c;
    }
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>>
            q; //dist, x, y, magic changed colour
    q.emplace(0, 1, 1, -1);
    dist[1][1] = 0;
    while (!q.empty()) {
        auto c = q.top();
        q.pop();
        if (get<1>(c) == m && get<2>(c) == m) break;
        if (dist[get<1>(c)][get<2>(c)] < get<0>(c)) continue;
        if (cc == -1) {
            for (int i = 0; i < 4; i++) {
                int cx = xm[i], cy = ym[i];
                if (get<1>(c) + cx < 1 || get<1>(c) + cx > m || get<2>(c) + cy < 1 ||
                    get<2>(c) + cy > m)
                    continue;
                if (grid[get<1>(c) + cx][get<2>(c) + cy] == -1) continue;
                int cg = 0;
                if (grid[get<1>(c) + cx][get<2>(c) + cy] != get<3>(c)) cg = 1;
                if (dist[get<1>(c) + cx][get<2>(c) + cy] == -1 ||
                    dist[get<1>(c) + cx][get<2>(c) + cy] > get<0>(c) + cg) {
                    dist[get<1>(c) + cx][get<2>(c) + cy] = get<0>(c) + cg;
                    q.emplace(get<0>(c) + cg, get<1>(c) + cx, get<2>(c) + cy, -1);
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int cx = xm[i], cy = ym[i];
                if (get<1>(c) + cx < 1 || get<1>(c) + cx > m || get<2>(c) + cy < 1 ||
                    get<2>(c) + cy > m)
                    continue;
                if (grid[get<1>(c) + cx][get<2>(c) + cy] == -1) { //use magic
                    int cg = 2;
                    if (dist[get<1>(c) + cx][get<2>(c) + cy] == -1 ||
                        dist[get<1>(c) + cx][get<2>(c) + cy] > get<0>(c) + cg) {
                        dist[get<1>(c) + cx][get<2>(c) + cy] = get<0>(c) + cg;
                        q.emplace(get<0>(c) + cg, get<1>(c) + cx, get<2>(c) + cy, cc);
                    }
                } else {
                    int cg = 0;
                    if (grid[get<1>(c) + cx][get<2>(c) + cy] != cc) cg = 1;
                    if (dist[get<1>(c) + cx][get<2>(c) + cy] == -1 ||
                        dist[get<1>(c) + cx][get<2>(c) + cy] > get<0>(c) + cg) {
                        dist[get<1>(c) + cx][get<2>(c) + cy] = get<0>(c) + cg;
                        q.emplace(get<0>(c) + cg, get<1>(c) + cx, get<2>(c) + cy, -1);
                    }
                }
            }
        }
    }
//    for (int i = 1; i <= m; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            printf("%2d ", dist[i][j]);
//        }
//        putchar('\n');
//    }
    cout << dist[m][m] << endl;
    return 0;
}
