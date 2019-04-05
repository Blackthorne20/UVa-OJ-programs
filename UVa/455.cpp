/*
455 - Periodic Strings

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=396
*/
#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // no. of test cases
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        if (i > 0) // print blank line between test cases
        {
            cout << endl;
        }

        string s;
        cin >> s;

        int size = s.size();
        for (int k = 1; k <= size; k++)
        {
            if (size % k == 0) // check only period lengths that are divisors of the string size
            {
                string t = s.substr(0, k), u = t; // copy substring of s from 0 to k into string u
                u.reserve(size);
                for (int l = 1; l < size / k; l++)
                {
                    u += t; // keep appending the substring until u is the same length as s
                }
                if (u == s)
                {
                    cout << k << endl; // print smallest period length
                    break;
                }
            }
        }
    }

    return 0;
}

