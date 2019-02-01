// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

#define endl '\n'

bool sortBySec(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numPeople, t = 1;
    while (cin >> numPeople)
    {
        if (t > 1)
        {
            cout << endl;
        }

        unordered_map<string, int> A;
        list<string> B;
        string name;
        for (int i = 0; i < numPeople; ++i)
        {
            cin >> name;
            A[name] = 0;
            B.emplace_back(name);
        }

        int amtSpent, numRecipients;
        for (int i = 0; i < numPeople; ++i)
        {
            cin >> name >> amtSpent >> numRecipients;
            if (numRecipients != 0)
            {
                A[name] -= amtSpent - amtSpent % numRecipients;
                int t = amtSpent / numRecipients;
                for (int j = 0; j < numRecipients; ++j)
                {
                    cin >> name;
                    A[name] += t;
                }
            }
        }

        for (auto s : B)
        {
            cout << s << " " << A[s] << endl;
        }

        ++t;
    }

    return 0;
}

