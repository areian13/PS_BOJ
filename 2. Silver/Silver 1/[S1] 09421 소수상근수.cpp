#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 486

int Sanggeun(int n)
{
    int result = 0;
    while (n > 0)
    {
        int d = n % 10;
        result += d * d;
        n /= 10;
    }
    return result;
}

bool IsSanggeun(int n)
{
    vector<bool> isVisited(MAX + 1, false);
    while (true)
    {
        n = Sanggeun(n);

        if (isVisited[n])
            return false;
        if (n == 1)
            return true;

        isVisited[n] = true;
    }
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = 2; i * j <= n; j++)
            isPrime[i * j] = false;
    }

    for (int i = 0; i <= n; i++)
    {
        if (!isPrime[i] || !IsSanggeun(i))
            continue;

        cout << i << '\n';
    }
}