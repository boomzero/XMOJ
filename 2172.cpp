#include <bits/stdc++.h>

using namespace std;
double mat[105][105];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1; ++j) {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (mat[i][j] != 0) {
                if (j != i) {
                    for (int k = 1; k <= n + 1; ++k) {
                        swap(mat[i][k], mat[j][k]);
                    }
                }
            }
        }
        if (mat[i][i] == 0) {
            cout << "No Solution" << endl;
            return 0;
        }
        double tmp = mat[i][i];
        for (int j = i; j <= n + 1; ++j) {
            mat[i][j] /= tmp;
        }
        for (int j = 1; j <= n; ++j) {
            if (j != i) {
                double tmp2 = mat[j][i];
                for (int k = n + 1; k >= 1; --k) {
                    mat[j][k] -= mat[i][k] * tmp2;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%.2lf\n", mat[i][n + 1]);
    }
    return 0;
}
