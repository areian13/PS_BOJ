#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    long long a, b, c;
    cin >> a >> b >> c;

    long long mul = a * b * c;
    array<int, 10> cnt = { 0, };
    while (mul > 0)
    {
        cnt[mul % 10]++;
        mul /= 10;
    }

    for (int i = 0; i < 10; i++)
        cout << cnt[i] << '\n';
}