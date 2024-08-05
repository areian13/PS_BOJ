#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long n;
    cin >> n;

    array<long long, 2> result = { n * n, 2 };
    cout << result[0] << ' ' << result[1] << '\n';
}