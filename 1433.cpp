#include <bits/stdc++.h>

using namespace std;
vector<pair < int, int>>
star;
int yb[50005];

int lb(int in) {
    return in & (-in);
}

map<int, int> star_map;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        x++;
        y++; //so that x and y are always greater than zero
        star.emplace_back(x, y);
    }
    sort(star.begin(), star.end());
    for (auto pa: star) {
        int x = pa.first, y = pa.second;
        //First, we check how many numbers in yb are lower than y
        //What we are actually calculating is the sum of yb[1] to yb[y]
        int fetch = y, sum = 0;
        while (fetch) {
            sum += yb[fetch];
            fetch -= lb(fetch);
        }
        //Ok, now we have the sum
        if (!star_map.count(sum)) star_map[sum] = 0; //If it doesn't exist yet, create it.
        star_map[sum]++; //include this star in star_map
        //Now we need to update yb[]
        fetch = y; //reusing this
        while (fetch <= 32005) {
            yb[fetch]++;
            fetch += lb(fetch);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!star_map.count(i)) star_map[i] = 0;
        cout << star_map[i] << endl;
    }
    return 0;
}

