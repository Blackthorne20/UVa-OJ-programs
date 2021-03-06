// OpenSource.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

#define endl '\n'

bool sortByInt(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line, projectName, studentName;
    unordered_set<string> students;
    unordered_set<string> projects;
    unordered_map<string, string> roster;
    unordered_map<string, int> count;

    while (getline(cin, line))
    {
        if (line != "0")
        {
            if (line.size() == 1 && isdigit(line[0]))
            {
                vector<pair<string, int>> countVec;
                for (auto i : roster)
                {
                    count[i.second]++;
                }
                countVec.reserve(count.size());
                for (auto i : count)
                {
                    countVec.push_back(make_pair(i.first, i.second));
                }
                sort(countVec.begin(), countVec.end(), sortByInt);
                for (auto i : countVec)
                {
                    cout << i.first << " " << i.second << endl;
                }
                students.clear();
                projects.clear();
                roster.clear();
                count.clear();
            }
            else if (any_of(line.begin(), line.end(), [](char c) { return (isupper(c)); }))
            {
                projectName = line;
                projects.insert(projectName);
                count[projectName] = 0;
            }
            else if (any_of(line.begin(), line.end(), [](char c) { return (islower(c)); }))
            {
                studentName = line;
                if (students.count(studentName) != 0 && roster[studentName] != projectName)
                {
                    roster.erase(studentName);
                }
                else if (roster.find(studentName) == roster.end())
                {
                    roster[studentName] = projectName;
                    students.insert(studentName);
                }
            }
        }
    }


    return 0;
}

