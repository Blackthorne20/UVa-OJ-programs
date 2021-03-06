// WhatIsTheMedian.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<unsigned> nums;

    unsigned X;
    while (cin >> X)
    {
        nums.push_back(X);
        auto med = nums.size() / 2;

        if (nums.size() % 2 == 0)
        {
            nth_element(nums.begin(), nums.begin() + med, nums.end());
            nth_element(nums.begin(), nums.begin() + med - 1, nums.end());
            auto s = (nums[med] + nums[med - 1]) / 2;
            cout << s << endl;
        }
        else
        {
            nth_element(nums.begin(), nums.begin() + med, nums.end());
            cout << nums[med] << endl;
        }
    }

    return 0;
}

