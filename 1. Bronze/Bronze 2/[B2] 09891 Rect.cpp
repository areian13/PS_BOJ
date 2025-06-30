#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Rect
{
    int x1, y1, x2, y2;
};

bool CanComp(Rect& a, Rect& b)
{
    int ax = abs(a.x1 - a.x2);
    int ay = abs(a.y1 - a.y2);
    int bx = abs(b.x1 - b.x2);
    int by = abs(b.y1 - b.y2);

    if (ax >= bx && ay >= by)
        return true;
    if (ax <= bx && ay <= by)
        return true;
    if (ax >= by && ay >= bx)
        return true;
    if (ax <= by && ay <= bx)
        return true;
    return false;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Rect> rects(n);
    for (auto& rect : rects)
        cin >> rect.x1 >> rect.y1 >> rect.x2 >> rect.y2;

    int result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            result += !CanComp(rects[i], rects[j]);
    }
    cout << result << '\n';
}