// CelebrityJeopardy.cpp : Defines the entry point for the console application.
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
    while (getline(cin, line))
    {
        cout << line << endl;
    }

    return 0;
}

