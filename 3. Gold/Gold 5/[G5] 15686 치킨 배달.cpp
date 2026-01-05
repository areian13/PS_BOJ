#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

struct Pos
{
    int r, c;
};

int CityDist(vector<Pos>& homes, vector<Pos>& chickens)
{
    int result = 0;
    for (auto& [hr, hc] : homes)
    {
        int dist = INF;
        for (auto& [cr, cc] : chickens)
            dist = min(dist, abs(hr - cr) + abs(hc - cc));
        result += dist;
    }
    return result;
}

int MinCityDist(int d, int k, vector<Pos>& homes,
    vector<Pos>& chickens, vector<Pos>& survived)
{
    int n = homes.size();
    int c = chickens.size();
    int m = survived.size();
    if (k == m)
        return CityDist(homes, survived);

    int result = INF;
    for (int i = d; i < c; i++)
    {
        survived[k] = chickens[i];
        result = min(result, MinCityDist(i + 1, k + 1, homes, chickens, survived));
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Pos> homes, chickens;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int p;
            cin >> p;

            if (p == 1)
                homes.push_back({ i,j });
            else if (p == 2)
                chickens.push_back({ i,j });
        }
    }

    vector<Pos> survived(m);
    int result = MinCityDist(0, 0, homes, chickens, survived);
    cout << result << '\n';
}