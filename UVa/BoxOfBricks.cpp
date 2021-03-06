// BoxOfBricks.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short n, setNo = 1;
    cin >> n;
    while (n != 0)
    {
        unsigned short h, avg = 0, sum = 0, displacement = 0;
        vector<unsigned short> stackHeights(n);
        for (int i = 0; i < n; i++)
        {
            cin >> h;
            stackHeights[i] = h;
            sum += h;
        }
        avg = sum / n;
        for (auto i : stackHeights)
        {
            if (i > avg)
            {
                displacement += i - avg;
            }
        }

        cout << "Set #" << setNo << endl;
        cout << "The minimum number of moves is " << displacement << "." << endl << endl;
        cin >> n;
        setNo++;
    }

    return 0;
}

