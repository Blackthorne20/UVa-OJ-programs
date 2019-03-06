#include <iostream>
#include <bitset>
#include <vector>
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
    bs[1] = 0;
    for (long long i = 2; i <= _sieve_size; ++i)
    {
        if (bs[(size_t)i])
        {
            for (long long j = i * i; j <= _sieve_size; j += i)
            {
                bs[(size_t)j] = 0;
            }
            primes.push_back((int)i);
        }
    }
}

bool isPrime(long long N)
{
    if (N <= _sieve_size)
    {
        return bs[(size_t)N];
    }
    for (int i = 0; i < (int)primes.size(); ++i)
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
    long long PF_idx = 0, PF = primes[(int)PF_idx], ans = 1;
    while (PF * PF <= N)
    {
        long long power = 0;
        while (N % PF == 0)
        {
            N /= PF; ++power;
        }
        ans *= (power + 1);
        PF = primes[(int)++PF_idx];
    }
    if (N != 1)
    {
        ans *= 2;
    }
    return ans;
}

vector<int> primeFactors(long long N)
{
    vector<int> factors;
    long long PF_idx = 0, PF = primes[(int)PF_idx];
    while (PF * PF <= N)
    {
        while (N % PF == 0)
        {
            N /= PF;
            factors.push_back((int)PF);
        }
        PF = primes[(int)++PF_idx];
    }
    if (N != 1)
    {
        factors.push_back((int)N);
    }
    return factors;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(10000000);

    return 0;
}

