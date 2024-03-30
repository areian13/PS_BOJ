#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int c, k, p;
    cin >> c >> k >> p;

    int result = k * (c * (c + 1) / 2) + p * (c * (c + 1) * (c * 2 + 1) / 6);
    cout << result << '\n';
}