#include <iostream>
using namespace std;
struct discount {
    int val = 0, startTime = 0;
} discountPile[40001];
int currentD = 0;
int main() {
    freopen("transfer.in", "r", stdin);
    freopen("transfer.out", "w", stdout);
    int n, price = 0, sval = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int tempM, tempP, tempT;
        cin >> tempM >> tempP >> tempT;
        if (tempM == 0) {
            price += tempP;
            currentD++;
            discountPile[currentD].val = tempP;
            discountPile[currentD].startTime = tempT;
        } else {
            bool foundDiscount = false;
            for (int j = sval; j <= currentD; ++j) {
                if (discountPile[j].startTime + 45 < tempT) {
                    sval = j;
                }
                if (discountPile[j].startTime + 45 >= tempT && discountPile[j].val >= tempP &&
                    discountPile[j].val != 0) {
                    foundDiscount = true;
                    discountPile[j].val = 0;
                    //discountPile[j].startTime = 0;
                    break;
                }
            }
            if (!foundDiscount) {
                price += tempP;
            }
        }
    }
    cout << price << endl;
    return 0;
}
