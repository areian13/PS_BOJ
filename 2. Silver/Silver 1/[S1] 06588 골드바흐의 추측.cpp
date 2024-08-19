#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000

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


    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        int right = n;
        while (true)
        {
            if (isPrime[right] && isPrime[n - right])
                break;
            right--;
        }

        printf("%d = %d + %d\n", n, n - right, right);
    }
}