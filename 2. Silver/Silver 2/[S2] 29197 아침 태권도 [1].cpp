#include <iostream>
#include <unordered_map>

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

    struct Hash
    {
        size_t operator()(const Vector& s) const
        {
            size_t h1 = hash<double>{}(s.slope);
            size_t h2 = hash<bool>{}(s.dir);
            return h1 ^ (h2 << 1);
        }
    };
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<Vector, bool, Vector::Hash> canSee;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        double slope = (x == 0 ? 1e+9 : (double)y / x);
        bool dir = x > 0 || (x == 0 && y > 0);
        Vector s = { slope, dir };
        canSee[s] = true;
    }

    int result = canSee.size();
    cout << result << '\n';
}