#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int p3, p4, p0;
    cin >> p3 >> p4 >> p0;

    int p = 0;
    while (p0 >= p)
    {
        if ((p3 + p) % 3 == 0 && (p4 + p0 - p) % 4 == 0)
            break;
        p++;
    }

    if (p0 < p)
        cout << -1 << '\n';
    else
    {
        int t3 = (p3 + p) / 3;
        int t4 = (p4 + p0 - p) / 4;
        cout << t3 << ' ' << t4 << '\n';
    }
}