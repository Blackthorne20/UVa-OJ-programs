//Evan Wood : Group Reverse : 11192 : Blackthorne20
//
//data structure required : stringstream
//
//tricks of the trade : using a stringstream to parse a string,
//                      partitioning a string using substrings

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    string line;

    while (getline(cin, line))
    {
        int n;
        string i_string;

        stringstream ss(line);
        ss >> n;
        ss >> i_string;

        if (n != 0)
        {
            //divide the string into n partitions of equal length
            int n_partitionLength = i_string.length() / n;

            //store each partition in a substring, reverse the substring, then print it
            for (int i = 0; i < n; i++)
            {
                string substring = i_string.substr(n_partitionLength*i, n_partitionLength);
                reverse(substring.begin(), substring.end());
                cout << substring;
            }
            cout << endl;
        }
    }

    return 0;
}

