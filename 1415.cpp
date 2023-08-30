#include <bits/stdc++.h>

using namespace std;

int x[7], v[7], sol[3][4];

char op[4] = {'+', '-', '*', '/'};

int dfs(int s)

{

    if (s == 3)
        return x[6] == 24;

    for (int i = 0; i < 7; ++i)

        if (v[i])
        {

            v[i] = 0;

            for (int j = i + 1; j < 7; ++j)

                if (v[j])
                {

                    v[j] = 0;

                    v[4 + s] = 1;

                    sol[s][0] = max(x[i], x[j]);

                    sol[s][2] = min(x[i], x[j]);

                    for (int k = 0; k < 4; ++k)
                    {

                        sol[s][1] = op[k];

                        bool good = true;

                        switch (op[k])
                        {

                        case '+':
                            x[4 + s] = sol[s][3] = sol[s][0] + sol[s][2];
                            break;

                        case '-':
                            x[4 + s] = sol[s][3] = sol[s][0] - sol[s][2];
                            break;

                        case '*':
                            x[4 + s] = sol[s][3] = sol[s][0] * sol[s][2];
                            break;

                        case '/':

                            if (sol[s][2] > 0 && sol[s][0] % sol[s][2] == 0)

                                x[4 + s] = sol[s][3] = sol[s][0] / sol[s][2];

                            else
                                good = false;

                            break;
                        }

                        if (good && dfs(s + 1))
                            return 1;
                    }

                    v[4 + s] = 0;

                    v[j] = 1;
                }

            v[i] = 1;
        }

    return 0;
}

int main()

{

    cin >> x[0] >> x[1] >> x[2] >> x[3];

    v[0] = v[1] = v[2] = v[3] = 1;

    if (dfs(0))
    {

        for (int i = 0; i < 3; ++i)
        {

            cout << sol[i][0] << (char)sol[i][1] << sol[i][2] << "=" << sol[i][3] << endl;
        }
    }
    else
        cout << "No answer!" << endl;

    return 0;
}
