/*
11057 - Exact Sum

This program reads in a series of books with their prices and picks two books
whose sum matches the amount of money available. If there is more than 1
solution, the books with the minimum price difference are chosen. The less
expensive book is output first, followed by the more expensive one.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // number of books
    while (cin >> N)
    {
        vector<int> books(N);
        for (int i = 0; i < N; i++)
        {
            cin >> books[i]; // read in price for each book
        }
        sort(books.begin(), books.end());

        int M; // amount of money available
        cin >> M;

        pair<int, int> ans;
        for (int i = books.size() - 1; i >= 0; i--) // traverse the list backwards
        {
            int x = books[i], y = M - x;
            if (binary_search(books.begin() + i + 1, books.end(), y)) // search only books that are more expensive
            {
                ans = { x, y };
                break;
            }
        }

        cout << "Peter should buy books whose prices are " << ans.first << " and " << ans.second << "." << endl << endl;
    }

    return 0;
}

