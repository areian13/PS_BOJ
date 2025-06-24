#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    scanf("%d", &n);

    array<int, 12> result = { 0, };
    for (int i = 0; i < n; i++)
    {
        char id[5];
        int d, m, h;
        scanf("%s %d/%d/%d", id, &d, &m, &h);

        result[m - 1]++;
    }

    for (int m = 0; m < 12; m++)
        cout << m + 1 << ' ' << result[m] << '\n';
}