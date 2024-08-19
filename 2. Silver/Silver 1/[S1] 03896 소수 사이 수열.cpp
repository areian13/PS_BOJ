#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'299'709

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

        int left = n;
        int right = n;

        while (!isPrime[left])
            left--;
        while (!isPrime[right])
            right++;

        int result = right - left;
        cout << result << '\n';
    }
}