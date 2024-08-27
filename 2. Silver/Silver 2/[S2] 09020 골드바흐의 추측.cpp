#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 10'000

array<int, 2> GoldbachPrime(int n, vector<bool>& isPrime)
{
    int mid = n / 2;
    for (int i = 0; i <= mid; i++)
    {
        if (isPrime[mid - i] && isPrime[mid + i])
            return { mid - i,mid + i };
    }
    return { -1,-1 };
}

int main()
{
    FastIO;

    vector<bool> isPrime(SIZE + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= SIZE; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = 2; i * j <= SIZE; j++)
            isPrime[i * j] = false;
    }

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        array<int, 2> result = GoldbachPrime(n, isPrime);
        cout << result[0] << ' ' << result[1] << '\n';
    }
}