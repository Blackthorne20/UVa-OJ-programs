// AgeSort.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

// A utility function to get maximum value in arr[] 
int getMax(vector<int> &arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
        }
    }
    return mx;
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(vector<int> &arr, int n, int exp)
{
    vector<int> output(n); // output array 
    int i, count[10] = { 0 };

    // Store count of occurrences in count[] 
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] now contains actual 
    //  position of this digit in output[] 
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the output array 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now 
    // contains sorted numbers according to current digit 
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixsort(vector<int> &arr, int n)
{
    // Find the maximum number to know number of digits 
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead 
    // of passing digit number, exp is passed. exp is 10^i 
    // where i is current digit number 
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n != 0)
    {
        vector<int> ages(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ages[i];
        }

        radixsort(ages, n);

        for (int i = 0; i < n; i++)
        {
            cout << ages[i];
            if (i < n - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
        cin >> n;
    }

    return 0;
}

