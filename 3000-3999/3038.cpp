#include <bits/stdc++.h>

using namespace std;

double dtr(double in) {
    return in / 180 * M_PI;
}

int main() {
    freopen("physics.in", "r", stdin);
    freopen("physics.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        double theta, v, d, g;
        //cin >> theta >> v >> d >> g;
        scanf("%lf%lf%lf%lf", &theta, &v, &d, &g);
        double ans = 2 * (cos(dtr(theta)) * v) * (cos(dtr(90 - theta)) * v) / g;
        while (v > 0.000001) { 
            v *= d;
            ans += 2 * (cos(dtr(theta)) * v) * (cos(dtr(90 - theta)) * v) / g;
        }
        printf("%.5lf\n", ans);
    }
    return 0;
}
