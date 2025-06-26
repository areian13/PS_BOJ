#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Circle
{
    int x, r;

    static bool IsIn(const Circle& a, const Circle& b)
    {
        int al = a.x - a.r, ar = a.x + a.r;
        int bl = b.x - b.r, br = b.x + b.r;

        return bl <= al && ar <= br;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Circle> circles(n);
    for (auto& circle : circles)
        cin >> circle.x >> circle.r;
    sort(circles.begin(), circles.end(),
        [](const Circle& a, const Circle& b)
        {
            if (Circle::IsIn(a, b))
                return true;
            if (Circle::IsIn(b, a))
                return false;
            return a.x < b.x;
        }
    );

    int result = 1;
    for (int i = 0; i < n; i++)
    {

    }
}