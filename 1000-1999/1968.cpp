#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXL = 77, MAXN = 111;
char r[MAXN], s[MAXN];
struct bigint {
    int a[MAXN];

    inline void init() {
		fgets(s,1110,stdin);
		int i=0;
		while(s[i]!='\n') i++;
		s[i]='\0';
        a[0] = strlen(s);
        for (int i = 1; i <= a[0]; ++i)
            a[i] = s[a[0] - i] - 48;
    }
    inline bool operator >(const bigint &t) {
        if (a[0] > t.a[0])
            return true;
        if (a[0] < t.a[0])
            return false;
        for (int i = a[0]; i; --i) {
            if (a[i] > t.a[i])
                return true;
            if (a[i] < t.a[i])
                return false;
        }
        return false;
    }
    inline void operator -=(const bigint &t) {
        for (int i = 1; i <= a[0]; ++i)
            if ((a[i] -= t.a[i]) < 0)
                a[i] += 10, --a[i + 1];
        for (; a[0] && !a[a[0]]; --a[0]);
    }
    inline void operator *=(int t) {
        for (int i = 1; i <= a[0]; ++i)
            a[i] *= t;
        for (int i = 1; i <= a[0]; ++i)
            a[i + 1] += a[i] / 10, a[i] %= 10;
        for (int i = a[0] + 1; a[i]; ++i, ++a[0])
            a[i + 1] += a[i] / 10, a[i] %= 10;
    }
} c, p[MAXL];
int main()
{
	freopen("excel.in","r",stdin);
	freopen("excel.out","w",stdout);
    for (int i = p[0].a[0] = p[0].a[1] = 1; i < MAXL; ++i)
        (p[i] = p[i - 1]) *= 26;
	fgets(r,1110,stdin);
	int i=0;
	while(r[i]!='\n') i++;
	r[i]='\0';
    c.init();
    for (int i = 1; i < MAXL; ++i)
        if (c > p[i])
            c -= p[i];
        else {
            for (int j = i; j; --j)
                for (char k = 'A'; k <= 'Z'; ++k)
                    if (c > p[j - 1])
                        c -= p[j - 1];
                    else {
                        putchar(k);
                        break;
                    }
            break;
        }
    puts(r);
    return 0;
}
