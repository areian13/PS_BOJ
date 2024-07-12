#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int r;
        double s;
        cin >> r >> s;

        if (cin.eof())
            break;

        int result = sqrt(r * (s + .16) / .067) + .5;
        cout << result << '\n';
    }
}