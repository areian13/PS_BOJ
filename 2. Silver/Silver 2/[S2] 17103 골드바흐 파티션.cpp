#include <iostream>
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

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        int result = 0;
        int mid = n / 2;
        for (int i = 0; 0 <= mid - i && mid + i <= MAX; i++)
            result += (isPrime[mid - i] && isPrime[mid + i]);
        cout << result << '\n';
    }
}