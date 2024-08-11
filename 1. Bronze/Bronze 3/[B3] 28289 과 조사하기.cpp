#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int p;
    cin >> p;

    array<int, 4> result = { 0, };
    for (int i = 0; i < p; i++)
    {
        int g, c, n;
        cin >> g >> c >> n;

        if (g == 1)
            result[0]++;
        else
            result[c == 1 ? c : c - 1]++;
    }

    int idx = 1;
    do
    {
        cout << result[idx] << '\n';
        idx = (idx + 1) % 4;
    } while (idx != 1);
}