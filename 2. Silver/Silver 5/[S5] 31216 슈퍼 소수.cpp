#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000

void SetSuperPrime(vector<int>& superPrime)
{
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;
        for (int j = 2; i * j <= MAX; j++)
            isPrime[i * j] = false;
    }

    vector<int> prime;
    for (int i = 1; i <= MAX; i++)
    {
        if (isPrime[i])
            prime.push_back(i);
    }

    int p = prime.size();
    for (int i = 0; i < p; i++)
    {
        if (isPrime[i + 1])
            superPrime.push_back(prime[i]);
    }
}

int main()
{
    FastIO;
    
    vector<int> superPrime;
    SetSuperPrime(superPrime);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        int result = superPrime[n - 1];
        cout << result << '\n';
    }
}