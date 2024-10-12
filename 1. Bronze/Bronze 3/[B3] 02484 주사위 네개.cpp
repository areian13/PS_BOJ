#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Score(array<int, 4>& dices)
{
    sort(dices.begin(), dices.end());

    if (dices[0] == dices[1] && dices[1] == dices[2] && dices[2] == dices[3])
        return 50'000 + dices[0] * 5'000;
    if (dices[0] == dices[1] && dices[1] == dices[2] ||
        dices[1] == dices[2] && dices[2] == dices[3])
        return 10'000 + dices[1] * 1'000;
    if (dices[0] == dices[1] && dices[2] == dices[3])
        return 2'000 + dices[0] * 500 + dices[2] * 500;
    if (dices[0] == dices[1])
        return 1'000 + dices[0] * 100;
    if (dices[1] == dices[2])
        return 1'000 + dices[1] * 100;
    if (dices[2] == dices[3])
        return 1'000 + dices[2] * 100;
    return dices[3] * 100;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        array<int, 4> dices;
        for (int i = 0; i < 4; i++)
            cin >> dices[i];

        result = max(result, Score(dices));
    }
    cout << result << '\n';
}