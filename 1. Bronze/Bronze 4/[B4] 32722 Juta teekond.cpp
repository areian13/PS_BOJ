#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<array<int, 2>, 3> map = { array<int, 2>{1,3},{6,8},{2,5} };

bool IsRightRoad(array<int, 3>& load)
{
    for (int i = 0; i < 3; i++)
    {
        if (load[i] != map[i][0] && load[i] != map[i][1])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    array<int, 3> load;
    for (int i = 0; i < 3; i++)
        cin >> load[i];

    if (IsRightRoad(load))
        cout << "JAH" << '\n';
    else
        cout << "EI" << '\n';
}