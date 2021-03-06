// ReverseAndAdd.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

bool isPalindrome(unsigned long P);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        unsigned long P = 0;
        unsigned short numIter = 0;
        cin >> P;
        bool found;

        do
        {
            unsigned long copy = P, Q = 0;
            while (copy)
            {
                Q *= 10;
                Q += copy % 10;
                copy /= 10;
            }

            P = P + Q;
            numIter++;

            found = isPalindrome(P);
        } while (!found);

        cout << numIter << " " << P << endl;
    }

    return 0;
}

bool isPalindrome(unsigned long P)
{
    vector<unsigned short> digits;
    while (P)
    {
        digits.push_back(P % 10);
        P /= 10;
    }

    vector<unsigned short> flipped(digits.size());
    reverse_copy(digits.begin(), digits.end(), flipped.begin());
    return (flipped == digits);
}
