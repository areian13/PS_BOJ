#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;

    friend int operator-(const Pos& a, const Pos& b)
    {
        return abs(a.x - b.x) + abs(a.y - b.y);
    }
};

int Perimeter(vector<Pos>& pos)
{
    int n = pos.size();
    int result = 0;
    for (int i = 0; i < n; i++)
        result += pos[i] - pos[(i + 1) % n];
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Pos> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].x >> pos[i].y;

    int result = Perimeter(pos);
    cout << result << '\n';
}