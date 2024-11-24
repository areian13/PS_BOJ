#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Get7Dwarf(array<int, 9>& hats)
{
    int sum = 0;
    for (int i = 0; i < 9; i++)
        sum += hats[i];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sum - hats[i] - hats[j] == 100)
            {
                swap(hats[i], hats[7]);
                swap(hats[j], hats[8]);
            }
        }
    }
}

int main()
{
    FastIO;

    array<int, 9> hats;
    for (int i = 0; i < 9; i++)
        cin >> hats[i];

    Get7Dwarf(hats);
    for (int i = 0; i < 7; i++)
        cout << hats[i] << '\n';
}