#include <bits/stdc++.h>

using namespace std;
int locks[15][6], currl[6];
int main() {
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d%d%d%d", &locks[i][1], &locks[i][2], &locks[i][3], &locks[i][4], &locks[i][5]);
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                for (int l = 0; l <= 9; l++) {
                    for (int p = 0; p <= 9; p++) {
                        int psrt = 0;
                        for (int id = 1; id <= n; id++) {
                            currl[1] = i;
                            currl[2] = j;
                            currl[3] = k;
                            currl[4] = l;
                            currl[5] = p;
                            int sim = 0;
                            for (int q = 1; q <= 5; q++) {
                                if (locks[id][q] == currl[q]) sim++;
                            }
                            if (sim == 4) {
                                psrt++;
                                continue;
                            } else if (sim == 3) {
                                for (int q = 1; q <= 4; q++) {
                                    while (currl[q] != locks[id][q] && currl[q + 1] != locks[id][q + 1]) {
                                        currl[q]++;
                                        currl[q + 1]++;
                                        if (currl[q] > 9) currl[q] = 0;
                                        if (currl[q + 1] > 9) currl[q + 1] = 0;
                                        if (currl[q] == locks[id][q] && currl[q + 1] == locks[id][q + 1]) {
                                            psrt++;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if (psrt == n)
                            ans++;
                    }
                }
            }
        }
    }
    printf ("%d", ans);
    return 0;
}

