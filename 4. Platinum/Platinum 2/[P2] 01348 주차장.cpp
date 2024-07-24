#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

int main()
{
    FastIO;

    int r, c;
    cin >> r >> c;

    vector<vector<char>> map(r, vector<char>(c));
    vector<Pos> car, park;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == 'C')
                car.push_back({ i,j });
            if (map[i][j] == 'P')
                park.push_back({ i,j });
        }
    }

    int n = car.size();
    int m = park.size();


}