//Evan Wood : Hay Points : 10295 : Blackthorne20
//
//data structure required: map
//
//tricks of the trade: creating dictionaries using stl::map

#include <iostream>
#include <string>
#include <map>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> hayPoint;
    int m, n;
    cin >> m >> n;

    //fill Hay Point dictionary
    for (int i = 0; i < m; i++)
    {
        string word;
        int value;

        cin >> word >> value;
        hayPoint.insert(make_pair(word, value));
    }

    //read job descriptions and assign salaries
    for (int i = 0; i < n; i++)
    {
        string word;
        int salary = 0;
        cin >> word;
        while (word != ".")
        {
            //if a word in the job description is in the dictionary,
            //add its value to the salary
            if (hayPoint.find(word) != hayPoint.end())
            {
                salary += hayPoint[word];
            }
            cin >> word;
        }

        cout << salary << endl;
    }

    return 0;
}

