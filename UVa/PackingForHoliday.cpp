// PackingForHoliday.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int L, W, H;
        cin >> L >> W >> H;

        cout << "Case " << i + 1 << ": ";
        if (L <= 20 && W <= 20 && H <= 20)
        {
            cout << "good" << endl;
        }
        else
        {
            cout << "bad" << endl;
        }
    }

    return 0;
}

