#include <bits/stdc++.h>

using namespace std;

int a[1000], b[1000];

int main()

{

    int n, m, ans = 0;

    cin >> n;

    int i, suma = 0;

    for (i = 1; i <= n; i++)
    {

        cin >> a[i];

        suma += a[i];
    }

    double ave1 = suma * 1.0 / n;

    cin >> m;

    int sumb = 0;

    for (i = 1; i <= m; i++)
    {

        cin >> b[i];

        sumb += b[i];
    }

    double ave2 = sumb * 1.0 / m;

    sort(b + 1, b + m + 1);

    bool t = true;

    //  while(t){

    //      t=false;

    //      for(i=1;i<=m;i++){

    //          if(b[i]<ave2&&b[i]>ave1&&b[i]!=201){

    //              t=true;

    //              suma+=b[i];

    //              sumb-=b[i];

    //              b[i]=201;

    //              break;

    //          }

    //      }

    //      if(t) ans++;

    //      ave1=suma*1.0/((n+ans)*1.0);

    //      ave2=sumb*1.0/((m-ans)*1.0);

    //  }

    int m1 = m;

    for (i = 1; i <= m1; i++)
    {

        if (b[i] > ave1 && b[i] < ave2)
        {

            ans++;

            m--;

            n++;

            suma += b[i];

            sumb -= b[i];

            ave1 = suma * 1.0 / (n * 1.0);

            ave2 = sumb * 1.0 / (m * 1.0);
        }
    }

    cout << ans;

    return 0;
}
