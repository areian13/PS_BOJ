#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n;
    cin >> n;

    long long result = n * (n - 1) * (n - 2) / 6;
    cout << result << '\n';
    cout << 3 << '\n';
}