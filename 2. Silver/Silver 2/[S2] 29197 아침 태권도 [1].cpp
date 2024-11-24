#include <iostream>
#include <unordered_set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Vector
{
    double slope;
    bool dir;

    friend bool operator==(const Vector& a, const Vector& b)
    {
        return a.slope == b.slope && a.dir == b.dir;
    }
};

namespace std
{
    template<>
    struct hash<Vector> {
        size_t operator()(const Vector& vec) const
        {
            size_t h1 = hash<double>{}(vec.slope);
            size_t h2 = hash<bool>{}(vec.dir);
            return h1 ^ (h2 << 1);
        }
    };
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_set<Vector> canSee;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        double slope = (x == 0 ? 1e+9 : (double)y / x);
        bool dir = x > 0 || (x == 0 && y > 0);
        Vector vec = { slope, dir };
        canSee.insert(vec);
    }

    int result = canSee.size();
    cout << result << '\n';
}