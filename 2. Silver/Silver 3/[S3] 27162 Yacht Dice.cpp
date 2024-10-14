#include <iostream>
#include <string>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Value(array<int, 3>& dice, int idx)
{
    if (1 <= idx && idx <= 6)
    {
        int cnt = 0;
        for (int i = 0; i < 3; i++)
            cnt += (dice[i] == idx);
        return idx * (cnt + 2);
    }
    else if (idx == 7)
    {
        if (dice[0] == dice[1] && dice[1] == dice[2])
            return dice[0] * 4;
        else if (dice[0] == dice[1] && dice[1] != dice[2])
            return dice[1] * 4;
        else if (dice[0] != dice[1] && dice[1] == dice[2])
            return dice[1] * 4;
    }
    else if (idx == 8)
    {
        if (dice[0] == dice[1] && dice[1] == dice[2])
        {
            if (dice[0] == 6)
                return dice[0] * 3 + 5 * 2;
            else
                return dice[0] * 3 + 6 * 2;
        }
        else if (dice[0] != dice[1] && dice[1] == dice[2])
        {
            return max(dice[1] * 3 + dice[0] * 2, dice[1] * 2 + dice[0] * 3);
        }
        else if (dice[0] == dice[1] && dice[1] != dice[2])
            return max(dice[1] * 3 + dice[2] * 2, dice[1] * 2 + dice[2] * 3);
    }
    else if (idx == 9)
    {
        if (dice[0] != dice[1] && dice[1] != dice[2])
        {
            if ((1 <= dice[0] && dice[0] <= 5) && (1 <= dice[1] && dice[1] <= 5) && (1 <= dice[2] && dice[2] <= 5))
                return 30;
        }
    }
    else if (idx == 10)
    {
        if (dice[0] != dice[1] && dice[1] != dice[2])
        {
            if ((2 <= dice[0] && dice[0] <= 6) && (2 <= dice[1] && dice[1] <= 6) && (2 <= dice[2] && dice[2] <= 6))
                return 30;
        }
    }
    else if (idx == 11)
    {
        if (dice[0] == dice[1] && dice[1] == dice[2])
            return 50;
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
            sum += dice[i];
        return sum + 6 + 6;
    }
    return 0;
}

int main()
{
    FastIO;

    string availPed;
    cin >> availPed;

    array<int, 3> dice;
    for (int i = 0; i < 3; i++)
        cin >> dice[i];
    sort(dice.begin(), dice.end());

    int result = 0;
    for (int i = 0; i < 12; i++)
        result = max(result, Value(dice, i + 1) * (availPed[i] == 'Y'));
    cout << result << '\n';
}