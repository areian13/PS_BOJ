#include <iostream>
#include <array>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool CanFormTriagle(array<int, 3>& a)
{
    return (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]);
}

bool IsSameTriagle(array<int, 3>& a, array<int, 3>& b)
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        array<int, 3> a;
        for (int i = 0; i < 3; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        array<int, 3> b;
        for (int i = 0; i < 3; i++)
            cin >> b[i];
        sort(b.begin(), b.end());

        bool foundRectangle = CanFormTriagle(a) && CanFormTriagle(b) && IsSameTriagle(a, b);
        string result = foundRectangle ? "YES" : "NO";
        cout << result << '\n';
    }
}