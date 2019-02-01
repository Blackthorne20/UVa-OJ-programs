// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N, N >= 0)
    {
        string output = "";
        if (N == 0)
        {
            output = "0";
        }
        else
        {
            while (N != 0)
            {
                char c = N % 3 + 48;
                output = c + output;
                N /= 3;
            }
        }
        cout << output << endl;
    }

    return 0;
}

