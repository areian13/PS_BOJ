#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        long long m;
        cin >> m;

        if (m == 0)
            break;

        long long result = m * (m - 1) + 1;
        cout << 'Y' << ' ' << result << '\n';
    }
}