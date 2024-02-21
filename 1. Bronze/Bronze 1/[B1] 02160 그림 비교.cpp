#include <iostream>
#include <vector>
#include <array>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define ROW 5
#define COL 7

int CountGap(array<array<char, COL>, ROW>& a, array<array<char, 7>, 5>& b)
{
    int result = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            result += (a[i][j] != b[i][j]);
    }
    return result;
}

array<int, 2> MinGap(vector<array<array<char, COL>, ROW>>& drawing)
{
    int n = drawing.size();

    int minGap = INT_MAX;
    array<int, 2> result = { 0,0 };
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int gap = CountGap(drawing[i], drawing[j]);
            if (gap < minGap)
            {
                minGap = gap;
                result = { i + 1,j + 1 };
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<array<array<char, COL>, ROW>> drawing(n);
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
                cin >> drawing[k][i][j];
        }
    }

    array<int, 2> result = MinGap(drawing);
    cout << result[0] << ' ' << result[1] << '\n';
}