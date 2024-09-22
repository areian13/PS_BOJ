#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000

bool IsPrime(int n)
{
    static vector<bool> isPrime(MAX + 1, true);
    static bool isInited = false;

    if (!isInited)
    {
        isInited = true;

        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= MAX; i++)
        {
            if (!isPrime[i])
                continue;

            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime[n];
}

int main()
{
    FastIO;

    int m, n;
    cin >> m >> n;

    for (int i = m; i <= n; i++)
    {
        if (IsPrime(i))
            cout << i << '\n';
    }
}