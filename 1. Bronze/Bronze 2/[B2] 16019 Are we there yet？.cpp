#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<int> a(4);
    for (int i = 0; i < 4; i++)
        cin >> a[i];

    vector<vector<int>> result(5, vector<int>(5, 0));
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = i; k < j; k++)
                result[i][j] += a[k];
            result[j][i] = result[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
}