#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b;
    cin >> a >> b;

    long long result = (long long)(a - 2) * b * (b + 1) / 2 + b + 1;
    cout << result << '\n';
}