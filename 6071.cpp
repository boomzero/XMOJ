#include <bits/stdc++.h>

using namespace std;

int n, size = 0;

struct line
{

    int x, y;

    line(int _x = 0, int _y = 0) { x = _x, y = _y; }

    bool operator<(const line &a) const
    {

        return y < a.y;
    }

} temp;

vector<line> ve;

vector<line>::iterator it;

void insert(line a) { ve.insert(lower_bound(ve.begin(), ve.end(), a), a); }

int main()
{

    char opt[2];
    int x, y, cnt = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {

        scanf("%s%d%d", opt, &x, &y);

        if (opt[0] == 'A')
        {

            temp = (line){x, y}, cnt = 0;

            while (1)
            {

                it = lower_bound(ve.begin(), ve.end(), temp);

                if (it != ve.end())
                {

                    if ((*it).x <= y && (*it).y >= x)
                    {

                        ve.erase(it), cnt++;

                        continue;
                    }
                }

                it = lower_bound(ve.begin(), ve.end(), temp);

                if (it != ve.begin())
                {

                    it--;

                    if ((*it).x <= y && (*it).y >= x)
                    {

                        ve.erase(it), cnt++;

                        continue;
                    }
                }

                break;
            }

            printf("%d\n", cnt);

            insert(temp);

            // for(int j=0;j<ve.size();j++) cerr << ve[j].x << ' ' << ve[j].y << ' '; cerr << endl;
        }

        else
            printf("%d\n", ve.size());
    }

    return 0;
}
