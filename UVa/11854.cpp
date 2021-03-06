// Egypt_11854.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    while (!(a == 0 && b == 0 && c == 0))
    {
        vector<int> tr = { a, b, c };
        sort(tr.begin(), tr.end());
        if (tr[2] * tr[2] == tr[0] * tr[0] + tr[1] * tr[1])
        {
            cout << "right" << endl;
        }
        else
        {
            cout << "wrong" << endl;
        }

        cin >> a >> b >> c;
    }

    return 0;
}

