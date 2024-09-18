#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'003'001

bool IsPalin(int n)
{
    string s = to_string(n);
    int d = s.size();
    for (int i = 0; i < d / 2; i++)
    {
        if (s[i] != s[d - 1 - i])
            return false;
    }
    return true;
}

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

    int result = n;
    while (!isPrime[result] || !IsPalin(result))
        result++;
    cout << result << '\n';
}