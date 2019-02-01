// UVa.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    string n;
    while (cin >> s >> n, !(s == 0 && n == "0"))
    {
        int r = 2 * s + 3, c = s + 3, cl = c * n.size() - 1, hr = r / 2;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < cl; ++j)
            {
                int rem = j % c, div = j / c;
                if (i == 0)
                {
                    if (rem != 0 && rem != c - 1 && rem != c - 2)
                    {
                        switch (n[div])
                        {
                        case '1':
                        case '4':
                            cout << " ";
                            break;
                        default:
                            cout << "-";
                        }
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else if (i > 0 && i < hr)
                {
                    if (rem == 0)
                    {
                        switch (n[div])
                        {
                        case '1':
                        case '2':
                        case '3':
                        case '7':
                            cout << " ";
                            break;
                        default:
                            cout << "|";
                        }
                    }
                    else if (rem == c - 2)
                    {
                        switch (n[div])
                        {
                        case '5':
                        case '6':
                            cout << " ";
                            break;
                        default:
                            cout << "|";
                        }
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else if (i == hr)
                {
                    if (rem != 0 && rem != c - 1 && rem != c - 2)
                    {
                        switch (n[div])
                        {
                        case '1':
                        case '7':
                        case '0':
                            cout << " ";
                            break;
                        default:
                            cout << "-";
                        }
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else if (i > hr && i < r - 1)
                {
                    if (rem == 0)
                    {
                        switch (n[div])
                        {
                        case '2':
                        case '6':
                        case '8':
                        case '0':
                            cout << "|";
                            break;
                        default:
                            cout << " ";
                        }
                    }
                    else if (rem == c - 2)
                    {
                        switch (n[div])
                        {
                        case '2':
                            cout << " ";
                            break;
                        default:
                            cout << "|";
                        }
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                else if (i == r - 1)
                {
                    if (rem != 0 && rem != c - 1 && rem != c - 2)
                    {
                        switch (n[div])
                        {
                        case '1':
                        case '4':
                        case '7':
                            cout << " ";
                            break;
                        default:
                            cout << "-";
                        }
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

