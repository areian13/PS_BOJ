#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 6> value = { 1,5,10,20,50,100 };

    int maxCost = 0;
    int idx = 0;
    for (int i = 0; i < 6; i++)
    {
        int cnt;
        cin >> cnt;

        int cost = cnt * value[i];
        if (cost >= maxCost)
        {
            maxCost = cost;
            idx = i;
        }
    }

    int result = value[idx];
    cout << result << '\n';
}