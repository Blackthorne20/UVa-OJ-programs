// FlipSort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'


//void mergeSort(vector<int> &set, int l, int r)
//{
//    if (r > l)
//    {
//        int m = l + (r - l) / 2;
//
//        mergeSort(set, l, m);
//        mergeSort(set, m + 1, r);
//
//        merge(set, l, m, r);
//    }
//}
//
//void merge(vector<int> &set, int l, int m, int r)
//{
//    
//}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N)
    {
        int numSwaps = 0;
        vector<int> set(N);
        for (int i = 0; i < N; i++)
        {
            cin >> set[i];
        }

        do
        {
            int newn = 0;
            for (int l = 0; l < N - 1; l++)
            {
                int r = l + 1;
                if (set[l] > set[r])
                {
                    swap(set[l], set[r]);
                    newn = r;
                    numSwaps++;
                }
            }
            N = newn;
        } while (N != 0);

        cout << "Minimum exchange operations : " << numSwaps << endl;
    }

    return 0;
}

