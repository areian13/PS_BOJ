#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 10'000'000

vector<bool> isPrime;
vector<int> compositePrime;

bool IsCompositePrime(string n)
{
    int d = n.size();

    if (d < 3)
        return false;

    if (isPrime[stoi(n)])
        return false;

    for (int i = 0; i < d; i++)
    {
        for (int j = 2; i + j <= d; j++)
        {
            if (i == 0 && j == d)
                continue;

            string partialPrime = n.substr(i, j);
            if (!isPrime[stoi(partialPrime)])
                return false;
        }
    }
    return true;
}

int main()
{
    FastIO;

    isPrime.resize(SIZE + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= SIZE; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = 2; i * j <= SIZE; j++)
            isPrime[i * j] = false;
    }

    compositePrime.resize(SIZE + 1);
    int lastCompositePrime = -1;
    for (int n = 0; n <= SIZE; n++)
    {
        if (IsCompositePrime(to_string(n)))
            lastCompositePrime = n;
        compositePrime[n] = lastCompositePrime;
    }


    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        int result = compositePrime[n];
        cout << result << '\n';
    }
}