//Evan Wood : The Jackpot : 10684 : Blackthorne20
//
//data structure required: vector
//
//tricks of the trade: Max 1D Range Sum

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while (N != 0)
    {
        vector<int> arr(N);
        int running_sum = 0, ans = 0;
        for (int i = 0; i < N; i++) // O(n)
        {
            cin >> arr[i];

            //add each streak to running_sum
            running_sum += arr[i];

            //ans gets the current maximum streak
            ans = max(ans, running_sum);

            //reset running_sum if it falls below 0
            if (running_sum < 0)
            {
                running_sum = 0;
            }
        }

        if (ans == 0)
        {
            //no winning streak was found
            cout << "Losing streak." << endl;
        }
        else
        {
            cout << "The maximum winning streak is " << ans << "." << endl;
        }

        cin >> N;
    }
    return 0;
}