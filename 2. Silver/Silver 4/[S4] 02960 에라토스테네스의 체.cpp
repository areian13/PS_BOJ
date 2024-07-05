#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int KthErasedPrime(int n, int k)
{
    vector<bool> isPrime(n + 1, true);
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!isPrime[i])
            continue;

        for (int j = 1; i * j <= n; j++)
        {
            if (isPrime[i * j])
            {
                isPrime[i * j] = false;
                cnt++;
            }

            if (cnt == k)
                return i * j;
        }
    }
    return -1;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int result = KthErasedPrime(n, k);
    cout << result << '\n';
}