/*
12015 - Google is Feeling Lucky

This program determines which website should appear when the "I'm Feeling Lucky"
button is pressed. A set of ten urls are given, each with a corresponding
relevancy value. The websites with the highest relevancy values are given as
output.
*/
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

#define endl '\n'
#define SIZE 10

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // number of test cases
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ":" << endl;

        // get 10 websites, find max relevancy value (O(n))
        vector<pair<int, string>> sites(SIZE);
        int max = INT_MIN;
        for (int j = 0; j < SIZE; j++)
        {
            int relevance;
            string url;
            
            cin >> url >> relevance;
            sites[j] = { relevance, url };

            if (relevance > max)
            {
                max = relevance;
            }
        }

        // find websites with max relevancy value, print url (O(n))
        for (auto i : sites)
        {
            if (i.first == max)
            {
                cout << i.second << endl;
            }
        }
    }

    return 0;
}

