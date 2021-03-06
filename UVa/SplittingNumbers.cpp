//Evan Wood : Splitting Numbers : 11933 : Blackthorne20
//
//data structure required: bitset
//
//tricks of the trade: converting from decimal to binary and vice versa,
//                     manipulating bits inside bitsets

#include <iostream>
#include <bitset>
using namespace std;

#define endl '\n';

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long n;

    cin >> n;
    while (n != 0)
    {
        //copy the binary value of n to bitsets a and b
        bitset<32> a(n), b(n);

        //true if ith bit containing 1 is even, false if odd;
        bool b_evenOne = true;

        for (int i = 0; i < a.size(); i++)
        {
            //find a bit containing 1
            if (a[i] == 1)
            {
                if (b_evenOne)
                {
                    //set ith bit in b to 0
                    b.flip(i);
                    b_evenOne = false;
                }
                else
                {
                    //set ith bit in a to 0
                    a.flip(i);
                    b_evenOne = true;
                }
            }
        }

        //convert from binary to decimal and print resulting numbers
        cout << a.to_ulong() << " " << b.to_ulong() << endl;
        cin >> n;
    }
    return 0;
}

