#include <iostream>
#include <array>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsGoodSlot(array<vector<int>, 3>& slot)
{
    for (int i = 0; i < 3; i++)
    {
        bool isGood = false;
        for (int num : slot[i])
            isGood |= (num == 7);

        if (!isGood)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<vector<int>, 3> slot;
    slot.fill(vector<int>(n));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> slot[i][j];
    }

    int result = IsGoodSlot(slot) ? 777 : 0;
    cout << result << '\n';
}