#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c;
};

array<int, 4> dr = { 1,1,-1,-1 };
array<int, 4> dc = { 1,-1,1,-1 };

int MaxBishop(const Pos& s, int d, vector<bool>& check, vector<vector<bool>>& map)
{
    if (!map[s.r][s.c])
        return d;

    int n = map.size();

    check[s.r + s.c] = true;
    check[s.r - s.c + n * 3 - 2] = true;

    int result = d + 1;
    int p = (s.r + s.c) & 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int np = (i + j) & 1;
            if (np == p && !check[i + j] && !check[i - j + n * 3 - 2])
                result = max(result, MaxBishop({ i,j }, d + 1, check, map));
        }
    }
    check[s.r + s.c] = false;
    check[s.r - s.c + n * 3 - 2] = false;

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

    array<int, 2> result = { 0,0 };
    vector<bool> check(n * 4 - 2, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int p = (i + j) & 1;
            result[p] = max(result[p], MaxBishop({ i,j }, 0, check, map));
        }
    }
    cout << result[0] + result[1] << '\n';
}