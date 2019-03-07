// Newspaper
//
// This program reads an article and calculates the money the author earns. 
// Some characters are given money values. Each time a character is read,
// The author earns the value associated with that character.

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<double> ascii(256, 0); //associative array (more efficient than map)

    int N; //number of test cases
    cin >> N;
    for (int i = 0; i < N; i++)
    {

        //fill array with values
        //----------------------
        int K; //number of characters with values
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            char c;
            double val;
            cin >> c;
            cin >> val; //given in cents
            ascii[c] = val / 100.0;
        }

        //read article 
        //------------
        string line;
        double sum = 0.0;
        int M; //number of lines to read
        cin >> M;
        cin.ignore(numeric_limits<streamsize>::max(), endl); //skip to next line of input
        for (int j = 0; j < M; j++)
        {
            getline(cin, line);
            for (auto c : line)
            {
                sum += ascii[c];
            }
        }
        cout << fixed << setprecision(2) << sum << "$" << endl;
        fill(ascii.begin(), ascii.end(), 0); //reset array
    }

    return 0;
}

