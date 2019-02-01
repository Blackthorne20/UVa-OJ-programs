// UVa.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string> dict; // (word, sorted word)
    unordered_map<string, int> anagrams; // (sorted word, number of instances)
    string s;
    while (cin >> s, s != "#")
    {
        string t = s;
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        sort(t.begin(), t.end());
        dict[s] = t;
        anagrams[t]++;
    }

    for (auto i : dict)
    {
        if (anagrams[i.second] == 1)
        {
            cout << i.first << endl;
        }
    }

    return 0;
}

