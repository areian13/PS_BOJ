#include <iostream>
#include <cmath>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 20'000'000
const int SQRT_MAX = sqrt(MAX);
vector<int> primes;

void MakePrimes()
{
    vector<bool> isPrime(SQRT_MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= SQRT_MAX; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j <= SQRT_MAX; j += i)
            isPrime[j] = false;
    }

    for (int i = 2; i <= SQRT_MAX; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}
void PrintPrimeFactors(int n)
{
    while (n != 1)
    {
        int pf = n;
        for (int i = 0; primes[i] * primes[i] <= n; i++)
        {
            if (n % primes[i] == 0)
            {
                pf = primes[i];
                break;
            }
        }

        cout << pf << ' ';
        n /= pf;
    }
    cout << '\n';
}

int main()
{
    FastIO;

    MakePrimes();

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        PrintPrimeFactors(n);
    }
}