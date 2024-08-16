#include <iostream>
using namespace std;
  
int main()
{
    freopen("a.in","r",stdin) ;
    freopen("a.out","w",stdout) ;
      
    int N;
    cin >> N;
  
    for (int x = 111; x <= 999; x += 111)
        if (x >= N) {
            cout << x << endl;
            break;
        }
  
    return 0;
}
