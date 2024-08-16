#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 2; --i) {
        if (!(i % 2)) {
            cout << "I love that ";
        } else {
            cout << "I hate that ";
        }
    }
    cout << "I hate it" << endl;
    return 0;
}

