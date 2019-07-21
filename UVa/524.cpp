/*
524 - Prime Ring Problem


*/
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

void backtrack(int& n, vector<int> & q, bitset<17> & nums, int i)
{
    if (i > n)
    {
        if (isPrime(q.back() + 1))
        {
            cout << 1;
            for (int j = 1; j < n; j++)
            {
                cout << " " << q[j];
            }
            cout << endl;
        }
        nums[q.back()] = false;
        q.pop_back();
        return;
    }
    for (int j = 2; j <= n; j++)
    {
        if (!nums[j] && isPrime(j + q.back()))
        {
            q.push_back(j);
            nums[j] = true;
            backtrack(n, q, nums, i + 1);
        }
    }
    nums[q.back()] = false;
    q.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(100);

    int n, t = 1;
    while (cin >> n)
    {
        bitset<17> nums(3);
        vector<int> q;
        q.reserve(n);
        q.push_back(1);
        if (t > 1)
        {
            cout << endl;
        }
        cout << "Case " << t << ":" << endl;
        backtrack(n, q, nums, 2);
        t++;
    }

    return 0;
}

