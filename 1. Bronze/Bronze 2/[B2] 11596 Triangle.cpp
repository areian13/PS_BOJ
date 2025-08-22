#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsRight(array<int, 3>& tri)
{
    return tri[0] * tri[0] + tri[1] * tri[1] == tri[2] * tri[2];
}

int main()
{
    FastIO;

    array<int, 3> a, b;
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < 3; i++)
        cin >> b[i];
    sort(b.begin(), b.end());

    bool result = IsRight(a) && IsRight(b) && a == b;
    if (result)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}