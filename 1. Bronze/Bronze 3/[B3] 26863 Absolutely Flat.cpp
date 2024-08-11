#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsFlat(array<int, 4>& a, int b)
{
    bool isSame = true;
    for (int i = 0; i < 4; i++)
        isSame &= (a[i] == a[0]);

    if (isSame)
        return true;

    int idx = 0;
    for (int i = 0; i < 4; i++)
    {
        if (a[idx] > a[i])
            idx = i;
    }
    a[idx] += b;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] != a[0])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    array<int, 4> a;
    for (int i = 0; i < 4; i++)
        cin >> a[i];

    int b;
    cin >> b;

    bool result = IsFlat(a, b);
    cout << result << '\n';
}