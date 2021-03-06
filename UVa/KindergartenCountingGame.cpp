// KindergartenCountingGame.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <regex>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line))
    {
        short numWords = 0;
        regex r("[A-Za-z]+");
        smatch m;

        while (regex_search(line, m, r))
        {
            line = m.suffix().str();
            numWords++;
        }

        cout << numWords << endl;
    }

    return 0;
}

