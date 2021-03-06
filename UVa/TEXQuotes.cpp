// TEXQuotes.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    bool isLeftQuote = true;
    while (getline(cin, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '"')
            {
                if (isLeftQuote)
                {
                    cout << "``";
                    isLeftQuote = false;
                }
                else
                {
                    cout << "''";
                    isLeftQuote = true;
                }
            }
            else
            {
                cout << line[i];
            }
        }
        cout << endl;
    }

    return 0;
}

