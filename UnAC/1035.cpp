#include <iostream>
#define fileIn 1
using namespace std;
void stringAdd(string &in)
{
    int year = stoi(in.substr(0, 4)), month = stoi(in.substr(4, 2)), day = stoi(in.substr(6, 2));
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day < 31)
    {
        day++;
        string temp = to_string(day);
        if (temp.length() == 1)
            temp.insert(0, "0");
        in[6] = temp[0];
        in[7] = temp[1];
        return;
    }
    else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && month < 12)
    {
        in[6] = '0';
        in[7] = '1';
        day = 1;
        month++;
        string temp = to_string(month);
        if (temp.length() == 1)
            temp.insert(0, "0");
        in[4] = temp[0];
        in[5] = temp[1];
        return;
    }
    else if (month == 12)
    {
        in[4] = '0';
        in[5] = '1';
        in[6] = '0';
        in[7] = '1';
        year++;
        string temp = to_string(year);
        in[0] = temp[0];
        in[1] = temp[1];
        in[2] = temp[2];
        in[3] = temp[3];
        return;
    }
    else if ((month == 4 || month == 6 || month == 9 || month == 11) && day < 30)
    {
        day++;
        string temp = to_string(day);
        if (temp.length() == 1)
            temp.insert(0, "0");
        in[6] = temp[0];
        in[7] = temp[1];
        return;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        in[6] = '0';
        in[7] = '1';
        day = 1;
        month++;
        string temp = to_string(month);
        if (temp.length() == 1)
            temp.insert(0, "0");
        in[4] = temp[0];
        in[5] = temp[1];
        return;
    }
    else
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if (day < 29)
            {
                day++;
                string temp = to_string(day);
                if (temp.length() == 1)
                    temp.insert(0, "0");
                in[6] = temp[0];
                in[7] = temp[1];
                return;
            }
            else
            {
                in[6] = '0';
                in[7] = '1';
                day = 1;
                month++;
                string temp = to_string(month);
                if (temp.length() == 1)
                    temp.insert(0, "0");
                in[4] = temp[0];
                in[5] = temp[1];
                return;
            }
        }
        else
        {
            if (day < 28)
            {
                day++;
                string temp = to_string(day);
                if (temp.length() == 1)
                    temp.insert(0, "0");
                in[6] = temp[0];
                in[7] = temp[1];
                return;
            }
            else
            {
                in[6] = '0';
                in[7] = '1';
                day = 1;
                month++;
                string temp = to_string(month);
                if (temp.length() == 1)
                    temp.insert(0, "0");
                in[4] = temp[0];
                in[5] = temp[1];
                return;
            }
        }
    }
}
int main()
{
#if fileIn == 1
    freopen("date.in", "r", stdin);
    freopen("date.out", "w", stdout);
#endif
    string date1, date2;
    cin >> date1 >> date2;
    if (date1 == date2)
    {
        for (int i = 0; i < date1.length(); ++i)
        {
            if (date1[i] != date1[date1.length() - i - 1])
            {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << 1 << endl;
    }
    else
    {
        int ans = 0;
        while (true)
        {
            bool isR = true;
            for (int i = 0; i < date1.length(); ++i)
            {
                if (date1[i] != date1[date1.length() - i - 1])
                {
                    isR = false;
                    break;
                }
            }
            if (isR)
                ans++;
            stringAdd(date1);
            if (date1 == date2)
            {
                isR = true;
                for (int i = 0; i < date1.length(); ++i)
                {
                    if (date1[i] != date1[date1.length() - i - 1])
                    {
                        isR = false;
                        break;
                    }
                }
                if (isR)
                    ans++;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
