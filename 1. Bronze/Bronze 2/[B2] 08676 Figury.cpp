#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];

    bool result = false;
    for (int i = 0; i < n - 2; i++)
    {
        array<bool, 3> has = { false, };
        has[f[i + 0]] = true;
        has[f[i + 1]] = true;
        has[f[i + 2]] = true;

        result |= has[0] && has[1] && has[2];
    }

    if (result == true)
        cout << "TAK" << '\n';
    else
        cout << "NIE" << '\n';
}