/*
11530 - SMS Typing

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2525
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define endl '\n'
#define SIZE 27 // letters in alphabet + spacebar

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // fill array
    // ----------
    vector<int> ascii(128, 0); // associative array (key = char, value = # of times needed to type char)
    string chars = "abcdefghijklmnopqrstuvwxyz ";
    vector<int> vals = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4,1 };
    for (int i = 0; i < SIZE; i++)
    {
        ascii[chars[i]] = vals[i];
    }

    // read input
    // ----------
    int T; // number of test cases
    cin >> T;
    string line;
    getline(cin, line); // skip to next line of input
    for (int i = 1; i <= T; i++)
    {
        getline(cin, line);

        int buttonPresses = 0;
        for (auto c : line)
        {
            buttonPresses += ascii[c];
        }

        cout << "Case #" << i << ": " << buttonPresses << endl;
    }

    return 0;
}

