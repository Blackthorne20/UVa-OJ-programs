// WordScramble.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line))
    {
        stack<char> reverse;
        for (auto c : line)
        {
            if (c == ' ')
            {
                while (!reverse.empty())
                {
                    cout << reverse.top();
                    reverse.pop();
                }
                cout << " ";
            }
            else
            {
                reverse.push(c);
            }
        }
        while (!reverse.empty())
        {
            cout << reverse.top();
            reverse.pop();
        }
        cout << endl;
    }

    return 0;
}

