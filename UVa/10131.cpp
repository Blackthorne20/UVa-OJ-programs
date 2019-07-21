// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
#include <tuple>
#include <list>
using namespace std;

#define endl '\n'

int LIS(vector<tuple<int, int, int>>& a, int i)
{
    int lmax = 1;
    if (i == 0)
    {
        return 1;
    }
    for (int j = 0; j < i - 1; j++)
    {
        if (get<1>(a[i]) > get<1>(a[j]))
        {
            lmax = max(LIS(a, j) + 1, lmax);
        }
    }
    return lmax;
}


bool sorter(tuple<int, int, int>& a, tuple<int, int, int>& b)
{
    //if (get<2>(a) == get<2>(b))
    //{
    //    if (get<1>(a) == get<1>(b))
    //    {
    //        return get<0>(a) > get<0>(b);
    //    }
    //    return get<1>(a) < get<1>(b);
    //}
    return get<2>(a) > get<2>(b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<tuple<int, int, int>> elephants;
    elephants.reserve(1000);

    int W, I, i = 1;
    while (cin >> W >> I)
    {
        elephants.push_back({ i, W, I });
        i++;
    }

    sort(elephants.begin(), elephants.end(), sorter);

    int n = elephants.size();

    LIS(elephants, n - 1);


    return 0;
}

