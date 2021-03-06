// Hajj-e-Akbar.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int caseNo = 1;
    string line;
    while (cin >> line, line != "*")
    {
        cout << "Case " << caseNo << ": ";
        if (line == "Hajj")
        {
            cout << "Hajj-e-Akbar" << endl;
        }
        else if (line == "Umrah")
        {
            cout << "Hajj-e-Asghar" << endl;
        }
        caseNo++;
    }

    return 0;
}

