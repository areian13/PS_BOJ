#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    unsigned long long n;
    cin >> n;

    int result = 64;
    while (~n & 1)
        result--, n >>= 1;
    cout << result << '\n';
}