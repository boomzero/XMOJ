#include <bits/stdc++.h>
 
int coors[3010][2]; /* x,y */
int ans[3010][3];   /* id */
int n, ncollinear;
 
int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &coors[i][0], &coors[i][1]);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int dx1 = coors[j][0] - coors[i][0];
            int dy1 = coors[j][1] - coors[i][1];
            for (int k = j+1; k < n; k++) {
                int dx2 = coors[k][0] - coors[j][0];
                int dy2 = coors[k][1] - coors[j][1];
                if (dy1 * dx2 == dy2 * dx1) {
                    ans[ncollinear][0]  = i+1;  /* i,j,k already sorted */
                    ans[ncollinear][1]  = j+1;
                    ans[ncollinear][2]  = k+1;
                    ncollinear++;
                }
            }
        }
    }
    printf("%d\n", ncollinear);
    for (int i = 0; i < ncollinear; i++) 
        printf ("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
}
