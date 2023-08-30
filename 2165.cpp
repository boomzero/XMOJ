#include <bits/stdc++.h>
using namespace std;
int a[10110], b, alen, q[10110], qlen, r;
char s[10010];
void read(int x[], int &xlen)
{
  cin >> s;
  xlen = strlen(s);
  for (int i = 0; i < xlen; ++i)
    x[xlen - i] = s[i] - '0';
}
void print(int len, int a[])
{
  for (int i = len; i >= 1; i--)
  {
    cout << a[i];
  }
  cout << endl;
}
int main()
{
  read(a, alen);
  cin >> b;
  for (int i = alen; i >= 1; i--)
  {
    r = r * 10 + a[i];
    q[i] = r / b;
    r %= b;
  }
  qlen = alen;
  while (qlen > 1 && q[qlen] == 0)
  {
    qlen--;
  }
  print(qlen, q);
  cout << r;
  return 0;
}
