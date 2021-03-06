// AddAll.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short N;
    cin >> N;

    while (N != 0)
    {
        int temp;
        priority_queue <int, vector<int>, greater<int> > H;

        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            H.push(temp);
        }

        int a, b, c, cost = 0;
        for (int i = 0; i < N - 1;i++)
        {
            a = H.top();
            H.pop();
            b = H.top();
            H.pop();
            c = (a + b);
            H.push(c);
            cost += c;
        }

        cout << cost << endl;
        cin >> N;
    }

    return 0;
}

