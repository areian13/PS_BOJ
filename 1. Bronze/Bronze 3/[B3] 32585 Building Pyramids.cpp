#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    long long result = (1LL * n * n * n + 3LL * n * n + 2LL * n) / 6;
    cout << result << '\n';
}