#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x, y, n;
    cin >> x >> y >> n;

    vector<vector<bool>> isCultivated(y, vector<bool>(x, false));
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        for (int j = y1; j <= y2; j++)
        {
            for (int k = x1; k <= x2; k++)
                isCultivated[j][k] = true;
        }
    }

    int result = 0;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            result += isCultivated[i][j];
    }
    cout << result << '\n';
}