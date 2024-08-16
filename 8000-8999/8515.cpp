#include <bits/stdc++.h>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
using namespace std;
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
    int h, w; cin >> h >> w;
    vector<deque<bool> > a(h, deque<bool>(w));
    repeat (y,h)
        repeat (x,w)
            cin >> a[y][x];
    int q; cin >> q;
    bool trivial = false;
    repeat (query,q) {
        int y, x, p; cin >> y >> x >> p; -- y; -- x;
        if (trivial) {
            if (query == q-1) {
                repeat (y,h) repeat (x,w) a[y][x] = p;
            }
        } else {
            int cnt = 0;
            function<void (int,int)> dfs = [&](int y, int x) {
                a[y][x] = p;
                cnt += 1;
                repeat (i,4) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (ny < 0 or h <= ny or nx < 0 or w <= nx)
                        continue;
                    if(a[ny][nx] != p)
                        dfs(ny, nx);
                }
            };
            if (a[y][x] != p)
                dfs(y,x); 
            if (cnt == h * w)
                trivial = true;
        }
    }
    repeat (y,h) {
        repeat (x,w) {
            if (x) cout << ' ';
            cout << a[y][x];
        }
        cout << endl;
    }
    return 0;
}
