/*
10935 - Throwing cards away I

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1876
*/

#include <iostream>
#include <queue>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n, n != 0)
    {
        queue<int> cards;
        for (int i = 1; i <= n; i++)
        {
            cards.push(i);
        }
        cout << "Discarded cards:";
        while (cards.size() > 1)
        {
            // discard card on top
            // -------------------
            cout << " " << cards.front();
            cards.pop();
            if (cards.size() > 1)
            {
                cout << ",";
            }

            // move new top card to bottom of deck
            // -----------------------------------
            int top = cards.front();
            cards.pop();
            cards.emplace(top);
        }
        cout << endl << "Remaining card: " << cards.front() << endl;
    }

    return 0;
}

