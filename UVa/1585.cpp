/*
1585 - Score

This program reads in a sequence of O's and X's and outputs a score. An O denotes a correct answer
and an X denotes an incorrect answer. The score is given by the total number of correct answers,
plus a one point bonus for each consecutive correct answer.
*/
#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // number of test cases
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string line;
        cin >> line;
        int score = 0, numConsecutiveCorrectAnswers = 1;
        for (auto c : line)
        {
            if (c == 'O')
            {
                score += numConsecutiveCorrectAnswers;
                numConsecutiveCorrectAnswers++;
            }
            else
            {
                numConsecutiveCorrectAnswers = 1;
            }
        }
        cout << score << endl;
    }

    return 0;
}

