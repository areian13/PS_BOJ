#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int hl, hh, sl, sh, vl, vh, r, g, b;
    cin >> hl >> hh >> sl >> sh >> vl >> vh >> r >> g >> b;

    double m = min({ r,g,b });
    double v = max({ r,g,b });
    double s = 255 * (v - m) / v;
    double h = (v == r ? 60 * (g - b) / (v - m)
        : (v == g ? 120 + 60 * (b - r) / (v - m)
            : 240 + 60 * (r - g) / (v - m)));
    if (h < 0)
        h += 360;

    bool result = hl <= h && h <= hh
        && sl <= s && s <= sh
        && vl <= v && v <= vh;
    if (result == true)
        cout << "Lumi will like it." << '\n';
    else
        cout << "Lumi will not like it." << '\n';
}