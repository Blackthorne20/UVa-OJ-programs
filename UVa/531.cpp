//Evan Wood : Compromise : 531 : Blackthorne20
//
//data structure required: vector
//
//tricks of the trade: string processing with dynamic programming
//                     (longest common subsequence)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    while (cin >> word)
    {
        // STEP 1: get input data
        vector<string> A, B;

        // store each word in first text in A
        while (word != "#")
        {
            A.push_back(word);
            cin >> word;
        }

        // store each word in second text in B
        cin >> word;
        while (word != "#")
        {
            B.push_back(word);
            cin >> word;
        }

        // STEP 2: create table with an additional column and row of zeros
        int m = A.size(), n = B.size();
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));


        // STEP 3: fill the table, get length of LCS
        // from ch6_03_str_align.cpp, pages 246 and 247
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // if A[i-1] and B[i-1] match, add 1 to LCS length
                // match = 1 point, mismatch = -1000000000 points
                table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 1 : -1000000000);


                // 
                // insert/delete = 0 points
                table[i][j] = max(table[i][j], table[i - 1][j] - 0); // delete
                table[i][j] = max(table[i][j], table[i][j - 1] - 0); // insert
            }
        }

        // STEP 4: print LCS
        int i = m, j = n;
        string outputString = "";
        bool first = true;

        // start from the bottom right corner of the table
        // (from QuestToSolve, I tried several different methods, but only
        // this one worked for all uDebug test cases.)
        while (table[i][j] > 0)
        {
            // if words match, append to string for printing
            if (A[i - 1] == B[j - 1])
            {
                outputString = first ? A[i - 1] + outputString : A[i - 1] + " " + outputString;
                first = false;

                // move diagonally
                i--;
                j--;
            }

            // otherwise move left or right, whichever has the greater LCS value
            else
            {
                table[i - 1][j] > table[i][j - 1] ? i-- : j--;
            }
        }

        // STEP 5: print output string
        cout << outputString << endl;
    }

    return 0;
}

