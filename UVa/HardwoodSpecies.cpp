// HardwoodSpecies.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string species;
    int T;
    cin >> T;
    cin.ignore();
    getline(cin, species);

    for (int i = 0; i < T; i++)
    {
        int count = 0;
        map<string, int> trees;
        getline(cin, species);
        while (species != "")
        {
            trees[species]++;
            getline(cin, species);
            count++;
        }

        for (auto iter = trees.begin(); iter != trees.end(); iter++)
        {
            double percent = 100.0f * iter->second / count;
            cout << iter->first << " " << fixed << setprecision(4) << percent << endl;
        }
        if (i != T - 1)
        {
            cout << endl;
        }
    }

    return 0;
}

