#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, 2> result = { 0,0 };
    bool turn = 1;
    while (n > 0)
    {
        result[turn] += (n + 1) / 2;
        n /= 2;
        turn = !turn;
    }
    cout << result[0] << ' ' << result[1] << '\n';
}