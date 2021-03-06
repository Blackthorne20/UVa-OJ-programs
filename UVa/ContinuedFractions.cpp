//Evan Wood : Continued Fractions : 834 : Blackthorne20
//
//data structure required: none
//
//tricks of the trade: finding the continued fraction
//                     representation of a given fraction

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numerator, denominator;
    while (cin >> numerator >> denominator)
    {
        int i = 0;
        while (numerator != 0 && denominator != 0)
        {
            //print symbol
            switch (i)
            {
            case 0:
                cout << "[";
                break;
            case 1:
                cout << ";";
                break;
            default:
                cout << ",";
                break;
            }

            //output first fraction
            cout << numerator / denominator;

            //take the denominator and divide it by the remainder
            //in the next step
            int temp = numerator % denominator;
            numerator = denominator;
            denominator = temp;
            i++;
        }
        cout << "]" << endl;
    }

    return 0;
}

