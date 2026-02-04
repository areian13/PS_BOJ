#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;
const int MAX = 5'000'000;
vector<int> primes(MAX + 1, INF);

void MakePrimes()
{
    primes[1] = 1;
    for (int i = 2; i <= MAX; i++)
    {
        if (primes[i] != INF) continue;
        primes[i] = i;
        if (1LL * i * i > MAX) continue;
        for (int j = i * i; j <= MAX; j += i)
            primes[j] = min(primes[j], i);
    }
}
void PrintPrimeFactors(int n)
{
    while (n != 1)
    {
        cout << primes[n] << ' ';
        n /= primes[n];
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