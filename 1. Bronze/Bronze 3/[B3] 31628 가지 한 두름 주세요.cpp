#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 10

bool CanMakeEggPlantBundle(vector<vector<string>>& eggPlant)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (eggPlant[i][0] != eggPlant[i][j])
                break;

            if (j + 1 == SIZE)
                return true;
        }
    }

    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (eggPlant[0][j] != eggPlant[i][j])
                break;

            if (i + 1 == SIZE)
                return true;
        }
    }

    return false;
}

int main()
{
    FastIO;

    vector<vector<string>> eggPlant(SIZE, vector<string>(SIZE));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cin >> eggPlant[i][j];
    }

    bool result = CanMakeEggPlantBundle(eggPlant);
    cout << result << '\n';
}