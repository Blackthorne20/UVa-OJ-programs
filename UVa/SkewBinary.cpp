// SkewBinary.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    cin >> n;
    while (n != "0")
    {
        int num = 0;
        auto place = n.size();
        for (auto c : n)
        {
            num += lround((c - 48) * (pow(2, place) - 1));
            place--;
        }
        cout << num << endl;
        cin >> n;
    }


    return 0;
}

