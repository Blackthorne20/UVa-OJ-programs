// Binomial Showdown
//
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //find n choose k
    int n, k;
    while (cin >> n >> k, n || k)
    {
        long double a = n; //convert n to double
        int b = max(k, n - k), c = min(k, n - k);
        for (int i = n - 1; i > b; --i) //compute n! divided by k! or (n-k)!, whichever is larger
        {
            a *= i;
        }
        long double d = c; //convert k or (n-k) to double
        for (int i = c - 1; i > 1; --i) //compute k! or (n-k)!
        {
            d *= i;
        }
        cout << (int)(a / d + 0.5) << endl;
    }

    return 0;
}

