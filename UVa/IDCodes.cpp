// IDCodes.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ID_code;
    getline(cin, ID_code);
    while (ID_code != "#")
    {
        if (next_permutation(ID_code.begin(), ID_code.end()))
        {
            cout << ID_code << endl;
        }
        else
        {
            cout << "No Successor" << endl;
        }

        getline(cin, ID_code);
    }

    return 0;
}

