//Evan Wood : Parentheses Balance : 673 : Blackthorne20
//
//data structure required: stack
//
//tricks of the trade: using switch statements to create
//                     a jump table, thereby saving some
//                     time

#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_numLines;
    string s_line;

    cin >> n_numLines;
    cin.ignore(5, endl);
    getline(cin, s_line);

    for (int i = 0; i < n_numLines; i++)
    {
        stack<char> parStack;
        bool isCorrect = true;
        const int n_length = s_line.length();

        for (int j = 0; j < n_length; j++)
        {
            switch (s_line[j])
            {
            //first three cases: push opening bracket onto stack
            case '(':
                parStack.push('(');
                break;
            case '{':
                parStack.push('{');
                break;
            case '[':
                parStack.push('[');
                break;

            //next three cases: found closing bracket, check to see
            //if its matching opening bracket is on top of the stack
            case ')':
                if (!parStack.empty() && parStack.top() == '(')
                {
                    //if it is, pop it off the stack and continue
                    parStack.pop();
                }
                else
                {
                    //no need to continue, so break out of loop
                    isCorrect = false;
                    j = n_length;
                }
                break;
            case '}':
                if (!parStack.empty() && parStack.top() == '{')
                {
                    parStack.pop();
                }
                else
                {
                    isCorrect = false;
                    j = n_length;
                }
                break;
            case ']':
                if (!parStack.empty() && parStack.top() == '[')
                {
                    parStack.pop();
                }
                else
                {
                    isCorrect = false;
                    j = n_length;
                }
                break;
            }
        }
        if (parStack.empty() && isCorrect)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        getline(cin, s_line);
    }

    return 0;
}

