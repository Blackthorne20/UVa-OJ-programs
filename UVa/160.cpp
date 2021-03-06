//Evan Wood : Factors and Factorials : 160 : Blackthorne20
//
//data structure required: vector of maps, sieve (bitset)
//
//tricks of the trade: using a sieve to generate prime numbers,
//                     finding prime factors of a number

#include <iostream>
#include <bitset>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef vector<int> vi;

//a^i = (a^(i+1)-1)/(a-1)
//P(f) = N * prod(1-(1/PF))

ll _sieve_size;
bitset<10000010> bs;
vi primes;

// keeps count of prime factors of N! up to N = 100
vector<map<int, int>> ct(101);

// sieve of eratosthenes
void sieve(ll upperbound)
{
    _sieve_size = upperbound + 1;

    // set everything to 1
    bs.set();
    bs[0] = bs[1] = 0;

    for (ll i = 2; i <= _sieve_size; i++)
    {
        if (bs[i])
        {
            // set all multiples of i greater than i to 0
            for (ll j = i * i; j <= _sieve_size; j += i)
            {
                bs[j] = 0;
            }
            primes.push_back((int)i);
        }
    }
}

// page 213
void primeFactors(ll N)
{
    // store prime factors of N in ct
    int i = N;
    ll PF_idx = 0, PF = primes[PF_idx];

    // 
    while (PF * PF <= N)
    {
        // keep dividing N by prime number until
        // it no longer divides evenly
        while (N % PF == 0)
        {
            N /= PF;
            ct[i][PF]++;
        }
        PF = primes[++PF_idx];
    }
    if (N != 1)
    {
        ct[i][N]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // generate prime numbers from 2 to 100
    sieve(100);

    for (ll i = 2; i <= 100; i++)
    {
        // copy prime factors for (i-1)!
        ct[i] = ct[i - 1];

        // add prime factors of i
        primeFactors(i);
    }

    int N;
    cin >> N;
    while (N != 0)
    {
        cout << setw(3) << right << N << "! =";

        int i = 1;
        for (auto iter : ct[N])
        {
            // move to next line after 15 numbers printed
            if (i == 16)
            {
                cout << endl << setw(9) << right << iter.second;
            }
            else
            {
                cout << setw(3) << right << iter.second;
            }
            i++;
        }
        cout << endl;
        cin >> N;
    }

    return 0;
}

