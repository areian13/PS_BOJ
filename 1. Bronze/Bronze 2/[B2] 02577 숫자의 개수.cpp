#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int mul = 1;
    for (int i = 0; i < 3; i++)
    {
        int val;
        cin >> val;

        mul *= val;
    }

    array<int, 10> result = { 0, };
    while (mul > 0)
    {
        result[mul % 10]++;
        mul /= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << result[i] << '\n';
}