#include <iostream>
#include <unordered_map>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;

    friend bool operator==(const Pos& a, const Pos& b)
    {
        return a.x == b.x && a.y == b.y;
    }

    struct Hash
    {
        size_t operator()(const Pos& p) const
        {
            size_t h1 = hash<int>{}(p.x);
            size_t h2 = hash<int>{}(p.y);
            return h1 ^ (h2 << 1);
        }
    };
};

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    FastIO;

    int n;
    cin>> n;

    unordered_map<Pos, bool, Pos::Hash> canSee;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin>>x >> y;

        int gcd = GCD(abs(x), abs(y));
        x /= gcd;
        y /= gcd;

        canSee[{ x,y }] = true;
    }

    int result = canSee.size();
    cout << result << '\n';
}