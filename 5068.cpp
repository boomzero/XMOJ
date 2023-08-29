#include <bits/stdc++.h>

using namespace std;
double a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    for (double i = -1000; i <= 1000; i += 0.001) {
        if (abs(a * i * i * i + b * i * i + c * i + d) < 0.0001) {
            printf("%.2f ",i);
        }
    }
    return 0;
}

