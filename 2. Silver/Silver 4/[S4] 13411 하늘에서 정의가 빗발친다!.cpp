#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Missile
{
    int x, y, s, i;

    double T() const { return double(x * x + y * y) / (s * s); }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Missile> m(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, s;
        cin >> x >> y >> s;
        m[i] = { x,y,s,i };
    }
    sort(m.begin(), m.end(),
        [](const Missile& a, const Missile& b)
        {
            if (a.T() != b.T()) return a.T() < b.T();
            return a.i < b.i;
        }
    );

    for (int i = 0; i < n; i++)
        cout << m[i].i + 1 << '\n';
}