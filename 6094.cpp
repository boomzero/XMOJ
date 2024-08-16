#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 30010
#define M 210
using namespace std;
unsigned long long hash[N][M] , base[M] , a[N];
int v[N];
char str[M];
int main()
{
    int n , m , top;
    long long ans = 0;
    scanf("%d%d%*d" , &n , &m);
	int i,j;
    for(i = 1 ; i <= n ; i ++ )
    {
        scanf("%s" , str + 1);
        for(int j = 1 ; j <= m ; j ++ ) hash[i][j] = hash[i][j - 1] * 131 + str[j];
    }
    base[0] = 1;
    for(i = 1 ; i <= m ; i ++ ) base[i] = base[i - 1] * 131;
    for(i = 1 ; i <= m ; i ++ )
    {
        for(j = 1 ; j <= n ; j ++ ) a[j] = hash[j][m] - hash[j][i] * base[m - i] + hash[j][i - 1] * base[m - i];
        sort(a + 1 , a + n + 1);
        memset(v , 0 , sizeof(v)) , top = 1 , v[1] = 1;
        for(j = 2 ; j <= n ; j ++ )
        {
            if(a[j] != a[j - 1]) top ++ ;
            v[top] ++ ;
        }
        for(j = 1 ; j <= top ; j ++ ) ans += (long long)v[j] * (v[j] - 1) / 2;
    }
    printf("%lld\n" , ans);
    return 0;
}
