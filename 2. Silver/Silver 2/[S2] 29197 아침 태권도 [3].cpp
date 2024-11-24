#include <iostream>
#include <unordered_set>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

struct Position
{
    int x, y;

    friend bool operator==(const Position& a, const Position& b)
    {
        return a.x == b.x && a.y == b.y;
    }
};

namespace std
{
    template<>
    struct hash<Position>
    {
        size_t operator()(const Position& position) const
        {
            size_t h1 = hash<int>{}(position.x);
            size_t h2 = hash<int>{}(position.y);

            return h1 ^ (h2 << 1);
        }
    };
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_set<Position> canSee;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        int gcd = GCD(abs(x), abs(y));
        x /= gcd;
        y /= gcd;

        canSee.insert({ x,y });
    }

    int result = canSee.size();
    cout << result << '\n';
}