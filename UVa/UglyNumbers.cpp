// UglyNumbers.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define endl '\n'

unsigned long long raise(unsigned long long n, int e);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long long num = 1;
    vector<unsigned long long> uglyNumbers;
    uglyNumbers.reserve(1500);
    uglyNumbers.push_back(1);
    unsigned i2, i3, i5;

    uglyNumbers[0] = 1;
    for (int i = 0; i < 1500; i++)
    {

    }
}

