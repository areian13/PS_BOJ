#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int MaxBishop(int r, int c, int d, vector<bool>& check, vector<vector<bool>>& map)
{
    int n = map.size();
    if (c >= n)
        r++, c = ~c & 1;
    if (r >= n)
        return d;

    int result = MaxBishop(r, c + 2, d, check, map);
    if (map[r][c] && !check[r + c] && !check[r - c + n * 3 - 2])
    {
        check[r + c] = check[r - c + n * 3 - 2] = true;
        result = max(result, MaxBishop(r, c + 2, d + 1, check, map));
        check[r + c] = check[r - c + n * 3 - 2] = false;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<bool>> map(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool a;
            cin >> a;
            map[i][j] = a;
        }
    }

    array<int, 2> result;
    vector<bool> check(n * 4 - 2, false);
    for (int i = 0; i < 2; i++)
        result[i] = MaxBishop(0, i, 0, check, map);
    cout << result[0] + result[1] << '\n';
}