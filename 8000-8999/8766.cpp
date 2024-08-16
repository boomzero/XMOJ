# include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAX = 1111;
const int INF = 1e9;
int migi[MAX][MAX], hidari[MAX][MAX], up[MAX][MAX], down[MAX][MAX];
int B[MAX], dist[MAX][MAX];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
    int W, H, N;
    cin >> W >> H >> N;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) migi[y][x] = hidari[y][x] = x;
    }
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) up[y][x] = down[y][x] = y;
    }
    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);
        for (int j = 0; j < M+1; j++) scanf("%d", B+j);
        for (int j = 0; j < M; j++) {
            int y = B[j]/W, x = B[j]%W;
            int ny = B[j+1]/W, nx = B[j+1]%W;
            if (y == ny) {
                if (x < nx) {
                    migi[y][x] = max(migi[y][x], nx);
                    hidari[ny][nx] = min(hidari[ny][nx], x);
                } else {
                    migi[ny][nx] = max(migi[ny][nx], x);
                    hidari[y][x] = min(hidari[y][x], nx);
                }
            } else {
                if (y < ny) {
                    up[y][x] = max(up[y][x], ny);
                    down[ny][nx] = min(down[ny][nx], y);
                } else {
                    up[ny][nx] = max(up[ny][nx], y);
                    down[y][x] = min(down[y][x], ny);
                }
            }
        }
    }
    for (int y = 0; y < H; y++) {
        int maxi = 0;
        for (int x = 0; x < W; x++) {
            maxi = max(maxi, migi[y][x]);
            migi[y][x] = maxi;
        }
        int mini = W;
        for (int x = W-1; x >= 0; x--) {
            mini = min(mini, hidari[y][x]);
            hidari[y][x] = mini;
        }
    }
    for (int x = 0; x < W; x++) {
        int maxi = 0;
        for (int y = 0; y < H; y++) {
            maxi = max(maxi, up[y][x]);
            up[y][x] = maxi;
        }
        int mini = H;
        for (int y = H-1; y >= 0; y--) {
            mini = min(mini, down[y][x]);
            down[y][x] = mini;
        }
    }
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) dist[i][j] = INF;
    dist[0][0] = 0;
    queue<pii> que;
    que.push(pii(0, 0));
    while (!que.empty()) {
        pii p = que.front(); que.pop();
        int y = p.first, x = p.second;
        if (migi[y][x] > x && dist[y][x+1] > dist[y][x]+1) dist[y][x+1] = dist[y][x]+1, que.push(pii(y, x+1));
        if (hidari[y][x] < x && dist[y][x-1] > dist[y][x]+1) dist[y][x-1] = dist[y][x]+1, que.push(pii(y, x-1));
        if (up[y][x] > y && dist[y+1][x] > dist[y][x]+1) dist[y+1][x] = dist[y][x]+1, que.push(pii(y+1, x));
        if (down[y][x] < y && dist[y-1][x] > dist[y][x]+1) dist[y-1][x] = dist[y][x]+1, que.push(pii(y-1, x));
    }
    if (dist[H-1][W-1] >= INF) {
        cout << "NO" << endl;
    } else {
        cout << dist[H-1][W-1] << endl;
    }
    return 0;
}
