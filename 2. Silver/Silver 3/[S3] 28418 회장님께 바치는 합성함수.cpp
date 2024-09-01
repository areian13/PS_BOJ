#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Discreiminact(int a, int b, int c, int d, int e)
{
    array<int, 3> p = { a * d * d,2 * a * d * e + b * d,a * e * e + b * e + c };
    array<int, 3> q = { a * d,b * d,c * d + e };
    array<int, 3> r;
    for (int i = 0; i < 3; i++)
        r[i] = p[i] - q[i];

    int D = r[1] * r[1] - 4 * r[0] * r[2];

    if (r[0] != 0)
    {
        if (D > 0)
            return "Go ahead";
        if (D == 0)
            return "Remember my character";
        if (D < 0)
            return "Head on";
    }
    if (r[1] != 0)
        return "Remember my character";
    else
    {
        if (r[2] == 0)
            return "Nice";
        else
            return "Head on";
    }
    return "null";
}

int main()
{
    FastIO;

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    string result = Discreiminact(a, b, c, d, e);
    cout << result << '\n';
}