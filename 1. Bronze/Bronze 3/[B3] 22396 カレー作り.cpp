#include <iostream>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int r0, w0, c, r;
        cin >> r0 >> w0 >> c >> r;

        if (r0 == 0 && w0 == 0 && c == 0 && r == 0)
            break;

        int result = max((int)ceil((double)(c * w0 - r0) / r), 0);
        cout << result << '\n';
    }
}