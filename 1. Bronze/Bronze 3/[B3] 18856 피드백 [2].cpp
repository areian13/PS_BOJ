#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000

int main()
{
    FastIO;

    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= MAX; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = 2; i * j <= MAX; j++)
            isPrime[i * j] = false;
    }

    int n;
    cin >> n;

    cout << n << '\n';
    for (int i = 0, k = 0; i < n; i++, k++)
    {
        while (k < MAX)
        {
            if (k == 1 || isPrime[k])
            {
                cout << k << ' ';
                break;
            }
            k++;
        }
    }
    cout << '\n';
}