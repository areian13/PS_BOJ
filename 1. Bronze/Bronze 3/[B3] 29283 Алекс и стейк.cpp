#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long k;
    cin >> k;

    long long n = k / 5;
    long long result = n * (n + 1) * 75 + (n + 1) * (k % 5) * 30;
    cout << result << '\n';
}