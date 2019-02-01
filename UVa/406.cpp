#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

long long _sieve_size;
bitset<10000010> bs;
vector<long long> primes;

void sieve(long long upperbound)
{
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = 0;
    primes.push_back(1);
    for (long long i = 2; i <= _sieve_size; ++i)
    {
        if (bs[(size_t)i])
        {
            for (long long j = i * i; j <= _sieve_size; j += i)
            {
                bs[(size_t)j] = 0;
            }
            primes.push_back(i);
        }
    }
}

bool isPrime(long long N)
{
    if (N <= _sieve_size)
    {
        return bs[(size_t)N];
    }
    for (auto i = 0; i < (int)primes.size(); ++i)
    {
        if (N % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}

long long numDiv(long long N)
{
    auto PF_idx = 0LL, PF = primes[(const unsigned int)PF_idx], ans = 1LL;
    while (PF * PF <= N)
    {
        long long power = 0;
        while (N % PF == 0)
        {
            N /= PF; ++power;
        }
        ans *= (power + 1);
        PF = primes[(const unsigned int)++PF_idx];
    }
    if (N != 1)
    {
        ans *= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(1000);

    int N, C;
    while (cin >> N >> C)
    {
        cout << N << " " << C << ":";
        auto size = upper_bound(primes.begin(), primes.end(), N) - primes.begin();
        auto range = size % 2 == 0 ? 2 * C : 2 * C - 1;
        if (range >= size)
        {
            for (auto i = 0; i < size; ++i)
            {
                cout << " " << primes[i];
            }
            cout << endl;
        }
        else
        {
            auto mid = size / 2, left = mid - range / 2, right = mid + range / 2;
            if (size % 2 == 0)
            {
                for (auto i = left; i < right; ++i)
                {
                    cout << " " << primes[i];
                }
            }
            else
            {
                for (auto i = left; i <= right; ++i)
                {
                    cout << " " << primes[i];
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

