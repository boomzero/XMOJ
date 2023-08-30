#include <bits/stdc++.h>
#include <ostream>
using namespace std;
class game
{
    int p1, p2; // r:1 p:2 s:3
public:
    game(const string &a, const string &b)
    {
        if (a == "Rock")
            p1 = 1;
        else if (a == "Paper")
            p1 = 2;
        else
            p1 = 3;
        if (b == "Rock")
            p2 = 1;
        else if (b == "Paper")
            p2 = 2;
        else
            p2 = 3;
    }
    friend ostream &operator<<(ostream &os, const game &game)
    {
        if ((game.p1 == 1 && game.p2 == 3) || (game.p1 == 2 && game.p2 == 1) || (game.p1 == 3 && game.p2 == 2))
            os << "Player1";
        else if ((game.p2 == 1 && game.p1 == 3) || (game.p2 == 2 && game.p1 == 1) || (game.p2 == 3 && game.p1 == 2))
            os << "Player2";
        else
            os << "Tie";
        return os;
    }
};
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        string a, b;
        cin >> a >> b;
        game ng(a, b);
        cout << ng << endl;
    }
    return 0;
}
