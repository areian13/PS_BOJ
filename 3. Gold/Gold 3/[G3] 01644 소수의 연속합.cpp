#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 4'000'000

void MakePrimes(vector<int>& primes)
{
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;

        primes.push_back(i);
        for (int j = i + i; j <= MAX; j += i)
            isPrime[j] = false;
    }
}

int main()
{
    FastIO;

    vector<int> primes;
    MakePrimes(primes);

    int p = primes.size();

    int n;
    cin >> n;

    int result = 0;
    int sum = 0;
    int left = 0, right = 0;
    while (right <= p)
    {
        if (right == p && sum < n)
            break;

        if (sum < n)
            sum += primes[right++];
        else if (sum > n)
            sum -= primes[left++];
        else if (sum == n)
        {
            result++;
            sum -= primes[left++];
        }
    }
    cout << result << '\n';
}