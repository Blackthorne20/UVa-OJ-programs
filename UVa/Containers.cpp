// Containers.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    getline(cin, line);
    int count = 1;

    while (line != "end")
    {
        vector<stack<char>> Term(1);
        for (auto c:line)
        {
            for (int i = 0; i < Term.size(); i++)
            {
                if (Term[i].empty())
                {
                    Term[i].push(c);
                    i = Term.size();
                }
                else if (c <= Term[i].top())
                {
                    Term[i].push(c);
                    i = Term.size();
                }
                else if (i == Term.size() - 1 && c > Term[i].top())
                {
                    stack<char> temp;
                    Term.push_back(temp);
                }
            }
        }
        cout << "Case " << count << ": " << Term.size() << endl;
        count++;
        getline(cin, line);
    }
    return 0;
}

