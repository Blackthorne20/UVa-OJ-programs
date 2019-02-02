// Overflow.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line))
    {
        cout << line << endl;

        string num1, num2, imax = to_string(LONG_MAX);
        char symbol;

        stringstream ss(line);
        ss >> num1 >> symbol >> num2;

        while (num1.size() > 1 && num1[0] == '0')
        {
            num1.erase(num1.begin());
        }
        while (num2.size() > 1 && num2[0] == '0')
        {
            num2.erase(num2.begin());
        }

        int size1 = num1.size(), size2 = num2.size(), msize = imax.size();

        if (size1 > 10)
        {
            cout << "first number too big" << endl;
        }
        else if (size1 == msize)
        {
            for (int i = 0; i < size1; i++)
            {
                if (num1[i] < imax[i])
                {
                    break;
                }
                else if (num1[i] > imax[i])
                {
                    cout << "first number too big" << endl;
                    break;
                }
            }
        }
        if (size2 > 10)
        {
            cout << "second number too big" << endl;
        }
        else if (size2 == msize)
        {
            for (int i = 0; i < size2; i++)
            {
                if (num2[i] < imax[i])
                {
                    break;
                }
                else if (num2[i] > imax[i])
                {
                    cout << "second number too big" << endl;
                    break;
                }
            }
        }

        switch (symbol)
        {
        case '*':
            if (size1 + size2 > 11 && num1 != "0" && num2 != "0")
            {
                cout << "result too big" << endl;
            }
            else if (size1 + size2 <= 11)
            {
                if (stoll(num1) * stoll(num2) > LONG_MAX)
                {
                    cout << "result too big" << endl;
                }
            }
            break;
        case'+':
            if (max(size1, size2) > 10)
            {
                cout << "result too big" << endl;
            }
            else
            {
                if (stoll(num1) + stoll(num2) > LONG_MAX)
                {
                    cout << "result too big" << endl;
                }
            }
            break;
        }
    }

    return 0;
}

